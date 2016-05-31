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

#define Numbers 0
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
		QThread::msleep(5);	
		//qDebug() << "qmlloaded " << qmlloaded ;	
		if(qmlloaded == 0){
				time_Diff = time.elapsed();
				qDebug() << "get time duration:" << time_Diff/1000.0;	
				spendtime += time_Diff/1000.0;
				time.start();
		}
	} while(qmlloaded !=  -1);
	
	QString tr_timeDiff = QString("%1").arg(spendtime);
	r_totaltime = tr_timeDiff;
	qDebug() << "total " << r_totaltime;	
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

