#include "DragScrollArea.h"
#include <QEvent>
#include <QMouseEvent>
#include <QScrollBar>

DragScrollArea::DragScrollArea(QWidget *parent)
	: QScrollArea(parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

DragScrollArea::~DragScrollArea()
{

}

bool DragScrollArea::event(QEvent* event)
{
	if (widget())	//没有滚动窗口的时候，不处理
	{
		static QPoint p;
		if (QEvent::MouseButtonPress == event->type())
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
			p = mouseEvent->pos();
		}
		else if (QEvent::MouseMove == event->type())
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
			if (Qt::LeftButton & mouseEvent->buttons())
			{
				p = mouseEvent->pos() - p;
				horizontalScrollBar()->setValue(horizontalScrollBar()->value() - p.x()*horizontalScrollBar()->maximum() / widget()->width());
				verticalScrollBar()->setValue(verticalScrollBar()->value() - p.y()*verticalScrollBar()->maximum() / widget()->height());
				p = mouseEvent->pos();
			}
		}
	}

	return QScrollArea::event(event);
}