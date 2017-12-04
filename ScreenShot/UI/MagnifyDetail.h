/*
* Description: 截图工具栏
* Author: 公子开明 KaiMing Prince
* Detail: 局部放大确认截图位置，并显示当前像素rgb值和截图范围
* Class： MagnifyDetail
* Implement: 本类实现了截图过程局部放大并增加网格确认结束点
*/
#ifndef _MAGNIFY_DETAIL_H__
#define _MAGNIFY_DETAIL_H__
#include <QLabel>

class MagnifyDetail : public QLabel
{
	Q_OBJECT

public:
	MagnifyDetail(QWidget *parent = Q_NULLPTR);
	~MagnifyDetail();
};
#endif //_MAGNIFY_DETAIL_H__