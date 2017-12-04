#include "DivLayer.h"
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
#include <QScreen>

DivLayer::DivLayer(QWidget *parent)
	: QWidget(parent, Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint),
	  m_shot_rect(0, 0, 0, 0),
	  m_label(new QLabel(this))
{
	m_label->resize(300, 200);
	setAttribute(Qt::WA_TranslucentBackground);
	resize(1920, 1080);
}

DivLayer::~DivLayer()
{

}

void DivLayer::paintEvent(QPaintEvent *event)
{
	QPainterPath path;
	path.addRect(rect());
	if (!m_shot_rect.isEmpty())
	{
		path.addRect(m_shot_rect);
	}
	QPainter p(this);
	p.setBrush(QColor("#78C8C8C8"));
	p.setClipPath(path);
	p.drawRect(rect());
	p.setBrush(Qt::black);
	p.drawRect(QRect(m_shot_rect.topLeft() - QPoint(0, 20), m_shot_rect.topLeft() + QPoint(80, 0)));
	p.setFont(QFont("Î¢ÈíÑÅºÚ", 10));
	p.setPen(Qt::white);
	p.drawText(m_shot_rect.topLeft()+QPoint(4, -4), QString("%1*%2").arg(m_shot_rect.width()).arg(m_shot_rect.height()));

	QPoint c = QCursor::pos();
	m_label->setPixmap(QApplication::primaryScreen()->grabWindow(0, c.x()-30, c.y()-20, 60, 40).scaled(m_label->size()));
}

void DivLayer::mousePressEvent(QMouseEvent *event)
{
	if (Qt::LeftButton == event->button())
	{
		m_shot_rect.setTopLeft(event->pos());
	}

	QWidget::mousePressEvent(event);
}

void DivLayer::mouseMoveEvent(QMouseEvent *event)
{
	if (Qt::LeftButton & event->buttons())
	{
		m_shot_rect.setBottomRight(event->pos());
		update();
	}

	QWidget::mouseMoveEvent(event);
}
