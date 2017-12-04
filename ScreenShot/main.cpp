#include "UI\DivLayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DivLayer w;
	w.show();
	return a.exec();
}
