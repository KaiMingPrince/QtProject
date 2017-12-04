/*
* Description: 截图工具栏
* Author: 公子开明 KaiMing Prince
* Detail: 目前包括以下功能：添加矩形，添加箭头，另存为到硬盘，撤销截图，确认截图
* Class： ToolBar
* Implement: 本类实现了截图确认了范围之后可以做的一些添加或者确认功能
*/
#ifndef _TOOL_BAR_H__
#define _TOOL_BAR_H__
#include <QWidget>

class ToolBar : public QWidget
{
	Q_OBJECT

public:
	ToolBar(QWidget *parent = Q_NULLPTR);
	~ToolBar();
};
#endif //_TOOL_BAR_H__