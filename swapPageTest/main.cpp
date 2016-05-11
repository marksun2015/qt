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

#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsScene>

#include "clicksimulator.h"

#pragma warning(default: 4512)

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	QQuickView *view=new QQuickView(); 
	view->setSource(QUrl("mainscreen.qml"));
	view->setSurfaceType(QSurface::OpenGLSurface);
	view->rootObject()->setSize(QSizeF(1024, 600));

	ClickSimulator *sim = new ClickSimulator();
	sim->m_viewer=view;
	QTimer::singleShot(200, sim, SLOT(click()));
	
	//QTimer *timer=new QTimer();
	//QObject::connect(timer,SIGNAL(timeout()),sim,SLOT(click())); 
	//timer->start(0);

    view->show();
    return app.exec();
}

