#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Widget w;
	w.resize(1024,600);
	w.setWindowFlags(Qt::FramelessWindowHint); 
	w.show();
	return a.exec();
}
