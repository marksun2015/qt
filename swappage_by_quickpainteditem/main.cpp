#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

#include "myimage.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QQuickView view;

	qmlRegisterType<MyImage>("CustomImage", 1, 0 , "MyImage");
	
	view.setSource(QUrl("main.qml"));
	view.show();

	return app.exec();
}
