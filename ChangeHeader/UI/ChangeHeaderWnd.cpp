#include "ChangeHeaderWnd.h"
#include <QFileDialog>
#include <QPainter>

ChangeHeaderWnd::ChangeHeaderWnd(QWidget *parent)
	: QWidget(parent, Qt::Tool | Qt::FramelessWindowHint)
{
	ui.setupUi(this);
	m_pDivWidget = new QWidget(ui.scrollArea);
	connect(ui.pushButton_close, &QPushButton::clicked, this, &QWidget::close);
	connect(ui.pushButton_upload, &QPushButton::clicked, this, &ChangeHeaderWnd::onUpload);
	connect(ui.horizontalSlider, &QSlider::valueChanged, this, &ChangeHeaderWnd::onScaledChanged);
	connect(ui.pushButton_anti, &QPushButton::clicked, std::bind(&ChangeHeaderWnd::RotateHeader, this, false));
	connect(ui.pushButton_clock, &QPushButton::clicked, std::bind(&ChangeHeaderWnd::RotateHeader, this, true));
	connect(ui.pushButton_ok, &QPushButton::clicked, this, &ChangeHeaderWnd::onOk);
	connect(ui.pushButton_cancel, &QPushButton::clicked, this, &ChangeHeaderWnd::onCancel);

	m_pDivWidget->setAttribute(Qt::WA_TranslucentBackground);
	m_pDivWidget->hide();
	m_pDivWidget->installEventFilter(this);
}

ChangeHeaderWnd::~ChangeHeaderWnd()
{

}

void ChangeHeaderWnd::RotateHeader(bool bClock)
{
	QPixmap pixmap = *(ui.label_header->pixmap());
	QMatrix matrix;
	matrix.rotate(bClock ? 90 : -90);
	pixmap = pixmap.transformed(matrix);
	ui.label_header->setPixmap(pixmap);
}

void ChangeHeaderWnd::OnUpdateResult(bool bSuccess)
{
	bSuccess ? onCancel() : ui.label_tip->setText(QString::fromLocal8Bit("ÐÞ¸ÄÍ·ÏñÊ§°Ü"));
}

void ChangeHeaderWnd::LoadHeader(const QPixmap& pixmap)
{
	m_originHeader = pixmap;
	int nSliderMinmum = 0;
	QPixmap scaledPixmap;
	if (m_originHeader.width() > m_originHeader.height())
	{
		scaledPixmap = m_originHeader.scaledToHeight(ui.scrollArea->height());
		nSliderMinmum = scaledPixmap.height() * 100 / m_originHeader.height();
	}
	else
	{
		scaledPixmap = m_originHeader.scaledToWidth(ui.scrollArea->width());
 		nSliderMinmum = scaledPixmap.width() * 100 / m_originHeader.width();
	}
	ui.scrollAreaWidgetContents->resize(m_originHeader.size());
	ui.horizontalSlider->setMinimum(nSliderMinmum);
	ui.horizontalSlider->setMaximum(100);
	ui.horizontalSlider->setValue(nSliderMinmum);
	ui.label_header->setPixmap(scaledPixmap);
	m_pDivWidget->show();
}

bool ChangeHeaderWnd::eventFilter(QObject* watched, QEvent* event)
{
	if (m_pDivWidget == watched && QEvent::Paint == event->type())	//»æÖÆÕÚÕÖ²ã
	{
		m_pDivWidget->resize(ui.scrollArea->size());
		QPainterPath path;
		path.addRect(m_pDivWidget->geometry());
		path.addEllipse(m_pDivWidget->geometry().adjusted(2, 2, -2, -2));
		QPainter p(m_pDivWidget);
		p.setRenderHint(QPainter::Antialiasing);
		p.setBrush(QColor(100, 100, 100, 200));
		p.setClipPath(path);
		p.drawRect(m_pDivWidget->geometry());
	}
	return QWidget::eventFilter(watched, event);
}

void ChangeHeaderWnd::onUpload()
{
	QString strFilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("Ñ¡ÔñÉÏ´«Í¼Æ¬"), "./", "*.jpg;*.png;*.bmp");
	if (strFilePath.isEmpty())
	{
		return;
	}
	LoadHeader(QPixmap(strFilePath));
}

void ChangeHeaderWnd::onScaledChanged(int nValue)
{
	QPixmap pixmap = m_originHeader.scaled(m_originHeader.size() * ((double)nValue / ui.horizontalSlider->maximum()));
	ui.scrollAreaWidgetContents->resize(pixmap.size());
	ui.label_header->setPixmap(pixmap);
}

void ChangeHeaderWnd::onOk()
{
	emit updateHeader(*ui.label_header->pixmap());
	onCancel();
}

void ChangeHeaderWnd::onCancel()
{
	m_pDivWidget->hide();
	ui.label_header->clear();
	ui.label_tip->clear();
	hide();
}
