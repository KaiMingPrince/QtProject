/********************************************************************
文件名  :    WhiteBoard
作者    :    @hxl
创建时间:    2016/4/6 11:27
版本	:	 1.0
文件描述:    鼠标绘制白板
版权	:	 Copyright ©2016 四川启程科技发展有限公司
*********************************************************************/
#ifndef _WHITE_BOARD_H_
#define _WHITE_BOARD_H_

#include <QWidget>
#include <QPen>
#include <QMutex>

class WhiteBoard : public QWidget
{
	Q_OBJECT
public:
	WhiteBoard(QWidget *parent = Q_NULLPTR);
	~WhiteBoard();

	//设置背景色
	void SetBkColor(const QColor& color);
	//绘图功能激活与否
	void SetDrawActive(bool bActive);
	//清空白板内容
	void ClearBoard();
	//设置画笔颜色
	void SetPenColor(QColor color);
	//设置画笔宽度
	void SetPenWidth(int nWidth);
	//设置擦除宽度
	void SetEraseWidth(int nWidth);
	//获取目前的白板底图
	QImage GetBaseImage() const;

	/****************************************************************************/
	//添加Bessel曲线
	void AddBesselPoints(const std::vector<QPoint>& vPoints, bool bDraw, bool bNewLine = true);
	//新图覆盖整个白板
	void OverwriteBaseImage(const QImage& image);

protected:
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
	virtual void resizeEvent(QResizeEvent *event);

	void UpdateImagePainter();	//对缓冲图层的刷新必须立刻执行,否则会出现画线断开的问题

signals:
	void besselPoints(const std::vector<QPoint>& vPoints, bool bDraw, bool bNewLine);
	void clearAll();

private:
	QVector<QPoint>							m_vPoints;
	mutable QMutex							m_mutex;
	QColor									m_bkColor;				//白板背景色
	QImage									m_image;

	//绘图路径
	QPainterPath							m_drawPath;
	QPen									m_drawPen;
	//擦除路径
	QPainterPath							m_erasePath;
	QPen									m_erasePen;

	bool									m_bNewLine;				//是否为一条新曲线
};

#endif // _WHITE_BOARD_H_
