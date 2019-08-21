#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_sync, &QPushButton::clicked, this, &MainWidget::onSyncClicked);
	connect(ui.pushButton_clear, &QPushButton::clicked, this, &MainWidget::onClearClicked);
	/*connect(ui.comboBox_pen_width, &QComboBox::currentIndexChanged, this, &MainWidget::onPenWidthChanged);
	connect(ui.comboBox_eraser_width, &QComboBox::currentIndexChanged, this, &MainWidget::onEraserWidthChanged);*/
}

void MainWidget::onSyncClicked(bool bClicked)
{
	if (bClicked) {
		connect(ui.widget, &WhiteBoard::besselPoints, ui.widget_2, &WhiteBoard::AddBesselPoints);
		connect(ui.widget, &WhiteBoard::clearAll, ui.widget_2, &WhiteBoard::ClearBoard);
		connect(ui.widget_2, &WhiteBoard::besselPoints, ui.widget, &WhiteBoard::AddBesselPoints);
		connect(ui.widget_2, &WhiteBoard::clearAll, ui.widget, &WhiteBoard::ClearBoard);
	}
	else {
		disconnect(ui.widget, &WhiteBoard::besselPoints, ui.widget_2, &WhiteBoard::AddBesselPoints);
		disconnect(ui.widget, &WhiteBoard::clearAll, ui.widget_2, &WhiteBoard::ClearBoard);
		disconnect(ui.widget_2, &WhiteBoard::besselPoints, ui.widget, &WhiteBoard::AddBesselPoints);
		disconnect(ui.widget_2, &WhiteBoard::clearAll, ui.widget, &WhiteBoard::ClearBoard);
	}
}

void MainWidget::onClearClicked()
{
	ui.widget->ClearBoard();
	ui.widget_2->ClearBoard();
}

void MainWidget::onPenWidthChanged(const QString& strText)
{
	ui.widget->SetPenWidth(strText.toInt());
	ui.widget_2->SetPenWidth(strText.toInt());
}

void MainWidget::onEraserWidthChanged(const QString& strText)
{
	ui.widget->SetEraseWidth(strText.toInt());
	ui.widget_2->SetEraseWidth(strText.toInt());
}
