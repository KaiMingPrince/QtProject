/*
* Description: 截图遮罩层
* Author: 公子开明 KaiMing Prince
* Detail: 默认自动识别窗口大小，标识截图大小，局部放大器
* Class： ToolBar
* Implement: 本类实现了截图范围确认的遮罩表现
*/
#ifndef _DIV_LAYER_H__
#define _DIV_LAYER_H__

#include <QWidget>

class QLabel;

class DivLayer : public QWidget
{
	Q_OBJECT

public:
	DivLayer(QWidget *parent = Q_NULLPTR);
	~DivLayer();

protected:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

private:
	QRect				m_shot_rect;
	QLabel*				m_label;
};
#endif //_DIV_LAYER_H__