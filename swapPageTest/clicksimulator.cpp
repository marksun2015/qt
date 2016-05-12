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
	int x=1, y=1;
	int count=0;
	int firsttime=1;

	QTime time; 
	time.start();
	int time_Diff; 
	float spendtime=0; 
	
	//press
	QMouseEvent *eventfp = new QMouseEvent(QEvent::MouseButtonPress, QPointF(x,y), 
				Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
	QCoreApplication::postEvent(s_viewer, eventfp);
	//release	
	QMouseEvent *eventfr = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(x,y), 
				Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
	QCoreApplication::postEvent(s_viewer, eventfr);

	do{
		//qDebug() << "run..." << qmlloaded;
		if(qmlloaded == 1){
			x=(count%3);
			qmlloaded=0;	
			//press
			QMouseEvent *event1 = new QMouseEvent(QEvent::MouseButtonPress, QPointF(x,y), 
						Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
			QCoreApplication::postEvent(s_viewer, event1);
			//release	
			QMouseEvent *event2 = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(x,y), 
						Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
			QCoreApplication::postEvent(s_viewer, event2);
			
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
			//qDebug() << "loop end..."; 
		}
	} while(count < Numbers);
	
	QString tr_timeDiff = QString("%1").arg(spendtime);
	r_totaltime = tr_timeDiff;
	
	//press
	QMouseEvent *event3 = new QMouseEvent(QEvent::MouseButtonPress, QPointF(0,0), 
				Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
	QCoreApplication::postEvent(s_viewer, event3);
	
	//release	
	QMouseEvent *event4 = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(0,0), 
				Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
	QCoreApplication::postEvent(s_viewer, event4);

}

ClickSimulator::ClickSimulator(QObject *parent) : 
QObject(parent)
{
}

void ClickSimulator::click()
{
#if 0
	//QApplication::setAttribute(Qt::AA_UseOpenGLES);                  
	//theQmlEngine = new QQmlEngine(&app);

	QQuickItem *root_window = new QQuickItem(m_viewer->rootObject());
	root_window->setSize(QSizeF(1024, 600)); 
	CPUrate cpurate(root_window);
	m_viewer->engine()->rootContext()->setContextProperty("cpurate",&cpurate);
#endif	

	Send_event *thread = new Send_event();
	thread->s_viewer=m_viewer;
	thread->start();
}

