#include "../clicksimulator.h"

#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsScene>
#include <QTest>
#include <QKeyEvent>
#include <QTouchEvent>

#include <QThread>
#include <QTime>

#define Numbers 200 
#define Category 3 

extern QString r_totaltime; 
extern int qmlloaded; 

class Send_event : public QThread {
	public:
		QQuickView* s_viewer; 
		void run();
};

void Send_event::run()
{
	int x=0, y=1;
	int count=0;

	QTime time; 
	time.start();
	int time_Diff; 
	float spendtime=0; 

	do{
		if(qmlloaded == 1){
			x=(count%3);
			qmlloaded=0;	

#if 1
			//press
			QMouseEvent *event1 = new QMouseEvent(QEvent::MouseButtonPress, QPointF(x,y), 
						Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
			QCoreApplication::postEvent(s_viewer, event1);
		
			//release	
			QMouseEvent *event2 = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(x,y), 
						Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
			QCoreApplication::postEvent(s_viewer, event2);
	
#endif		
#if 0
			//QTouchEvent * event1 = new QTouchEvent(t,QTouchEvent::TouchScreen,Qt::NoModifier,states,tpList);
			QTouchEvent * event1 = new QTouchEvent(QEvent::TouchBegin, 
												   QTouchEvent::TouchScreen, 
												   Qt::NoModifier, 
												   0,
												   QList<QTouchEvent::TouchPoint>()
												   << createTouchPoint(1, Qt::TouchPointPressed, QPointF(x,y), QPointF(x,y), QPointF(x,y))
												   << createTouchPoint(2, Qt::TouchPointPressed, QPointF(x,y), QPointF(x,y), QPointF(x,y)));
			QCoreApplication::postEvent(s_viewer, event1);
#endif		
				
			QThread::msleep(10);	
			count++;
			
			if(count==Numbers){
				time_Diff = time.elapsed();
				qDebug() << "Category" << y << "time:" << time_Diff/1000.0;	
				spendtime += time_Diff/1000.0;
				
				count=0;
				y++;

				time.start();

				if(y>Category){
					break;	
				}
			}
		}
	} while(count < Numbers);
	
	QString tr_timeDiff = QString("%1").arg(spendtime);
	r_totaltime = tr_timeDiff;
	
#if 1
	//press
	QMouseEvent *event3 = new QMouseEvent(QEvent::MouseButtonPress, QPointF(0,0), 
				Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
	QCoreApplication::postEvent(s_viewer, event3);
	
	//release	
	QMouseEvent *event4 = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(0,0), 
				Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
	QCoreApplication::postEvent(s_viewer, event4);
#endif		

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

