#pragma once

#include <QWidget>
#include "ui_WhiteBoard.h"

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = Q_NULLPTR);

protected slots:
	void onSyncClicked(bool bClicked);
	void onClearClicked();
	void onPenWidthChanged(const QString& strText);
	void onEraserWidthChanged(const QString& strText);
private:
	Ui::WhiteBoardClass ui;
};
