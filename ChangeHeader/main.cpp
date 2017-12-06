#include "UI/ChangeHeaderWnd.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ChangeHeaderWnd w;
	w.show();
	return a.exec();
}
