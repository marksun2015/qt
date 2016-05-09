#if !defined(WIN32)
#   include <signal.h>
#endif

#include <string>

#pragma warning(disable: 4512)
#include <QApplication>
#include <QDesktopWidget>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickView>
#include <QScreen>
#include <QTemporaryFile>
#include <vector>

#include <QTime>
#include <QtCore>
#include <QDebug>
#include <QObject>

#include <QFile>
#include "qmlapplicationviewer.h"
#include "clicksimulator.h"

#pragma warning(default: 4512)

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	QmlApplicationViewer viewer;
	viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
	viewer.setMainQmlFile(QLatin1String("main.qml"));
	//viewer.showMaximized();

	ClickSimulator sim(&viewer);
	QTimer timer;
	sim.connect(&timer, SIGNAL(timeout()), SLOT(click()));
	timer.start(1000);
		 
    viewer.show();
    return app.exec();
}

#include "main.moc"
