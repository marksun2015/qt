#include "clicksimulator.h"

#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsScene>
#include <QTest>
#include <QKeyEvent>

#include <QThread>
#include <QTime>

#define Numbers 100 

class Send_event : public QThread {
	public:
		QQuickView* s_viewer; 
		void run();
};

void Send_event::run()
{
	int x=0, y=300;
	int count=0;
	
	while (count < Numbers) {
		x=(count%3);
		
		//press
		QMouseEvent *event1 = new QMouseEvent(QEvent::MouseButtonPress, QPointF(x,y), 
					Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
		QCoreApplication::postEvent(s_viewer, event1);
		
		//release	
		QMouseEvent *event2 = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(x,y), 
					Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
		QCoreApplication::postEvent(s_viewer, event2);
		
        QThread::msleep(100);	
		count++;
	}
}

ClickSimulator::ClickSimulator(QObject *parent) : 
QObject(parent)
{
}

void ClickSimulator::click()
{
	Send_event *thread = new Send_event();
	thread->s_viewer=m_viewer;
	thread->start();
}

