#include "WhiteBoard.h"

#include <QPainter>
#include <QMouseEvent>
#include <QMutexLocker>

WhiteBoard::WhiteBoard(QWidget *parent)
: QWidget(parent),
  m_drawPen(Qt::red, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin),
  m_erasePen(Qt::white, 6, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin),
  m_bkColor(Qt::white),
  m_bNewLine(false)
{
}

WhiteBoard::~WhiteBoard()
{
}

void WhiteBoard::mousePressEvent(QMouseEvent* event)
{
	const QPoint& pos = event->localPos().toPoint();

	if (Qt::LeftButton == event->button())
	{
		m_vPoints.push_back(pos);
		m_drawPath = QPainterPath(pos);
		m_bNewLine = true;
	}
	else if (Qt::MidButton == event->button())
	{
		emit clearAll();
		ClearBoard();
	}
	else if (Qt::RightButton == event->button())
	{
		m_vPoints.push_back(pos);
		m_erasePath = QPainterPath(pos);
		m_bNewLine = true;
	}
	else
	{
		QWidget::mousePressEvent(event);
	}
}

void WhiteBoard::mouseMoveEvent(QMouseEvent *event)
{
	if ((Qt::LeftButton | Qt::RightButton) & event->buttons())
	{
		bool bDraw = (Qt::LeftButton & event->buttons());
		QPainterPath& path = bDraw ? m_drawPath : m_erasePath;
		m_vPoints.push_back(event->localPos().toPoint());
		if (m_vPoints.size() == 3)
		{
			path = QPainterPath(path.currentPosition());
			path.cubicTo(m_vPoints.at(0), m_vPoints.at(1), m_vPoints.at(2));
			UpdateImagePainter();
			update();

			emit besselPoints(m_vPoints.toStdVector(), bDraw, m_bNewLine);
			m_bNewLine = false;
			m_vPoints.clear();
		}
	}
	else
	{
		QWidget::mouseMoveEvent(event);
	}
}

void WhiteBoard::mouseReleaseEvent(QMouseEvent *event)
{
	m_vPoints.clear();

	if (!m_drawPath.isEmpty())
	{
		m_drawPath = QPainterPath();
	}
	if (!m_erasePath.isEmpty())
	{
		m_erasePath = QPainterPath();
	}

	QWidget::mouseReleaseEvent(event);
}

void WhiteBoard::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.fillRect(rect(), m_bkColor);
	QMutexLocker locker(&m_mutex);
	painter.drawImage(QPoint(0, 0), m_image);
}

void WhiteBoard::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);

	QImage image(width(), height(), QImage::Format_RGBA8888);
	//对于内存背景图来说，背景色应该是全透明的
	image.fill(QColor("#00ffffff"));
	//当白板已经有数据的时候，把之前的数据画到新图像上
	QMutexLocker locker(&m_mutex);
	if (!m_image.isNull())
	{
		QPainter p(&image);
		p.drawImage(0, 0, m_image);
	}
	m_image = image;
}

void WhiteBoard::UpdateImagePainter()
{
	QMutexLocker locker(&m_mutex);
	QPainter imagePainter(&m_image);
	imagePainter.setRenderHint(QPainter::Antialiasing);
	if (!m_drawPath.isEmpty())
	{
		imagePainter.setPen(m_drawPen);
		imagePainter.drawPath(m_drawPath);
	}

	if (!m_erasePath.isEmpty())
	{
		imagePainter.setPen(m_erasePen);
		//清除模式下只跟画笔宽度相关，任意颜色效果相同
		imagePainter.setCompositionMode(QPainter::CompositionMode_Clear);
		imagePainter.drawPath(m_erasePath);
	}
}

void WhiteBoard::SetBkColor(const QColor& color)
{
	m_bkColor = color;
}

void WhiteBoard::ClearBoard()
{
	{
		QMutexLocker locker(&m_mutex);
		//对于内存背景图来说，背景色应该是全透明的
		m_image.fill(QColor("#00ffffff"));
	}
	m_drawPath = QPainterPath();
	QMetaObject::invokeMethod(this, "update");
}

void WhiteBoard::SetPenColor(QColor color)
{
	m_drawPen.setColor(color);
}

void WhiteBoard::SetPenWidth(int nWidth)
{
	m_drawPen.setWidth(nWidth);
}

void WhiteBoard::SetEraseWidth(int nWidth)
{
	m_erasePen.setWidth(nWidth);
}

QImage WhiteBoard::GetBaseImage() const
{
	QMutexLocker locker(&m_mutex);
	return m_image.copy();
}

void WhiteBoard::AddBesselPoints(const std::vector<QPoint>& vPoints, bool bDraw, bool bNewLine)
{
	QPainterPath& path = bDraw ? m_drawPath : m_erasePath;
	path = (bNewLine ? QPainterPath(vPoints.at(0)) : QPainterPath(path.currentPosition()));
	path.cubicTo(vPoints.at(0), vPoints.at(1), vPoints.at(2));
	UpdateImagePainter();
	QMetaObject::invokeMethod(this, "update");
}

void WhiteBoard::OverwriteBaseImage(const QImage& image)
{
	{
		QMutexLocker locker(&m_mutex);
		m_image = image.scaled(size()).copy();
	}
	QMetaObject::invokeMethod(this, "update");
}