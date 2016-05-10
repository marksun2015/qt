#include "clicksimulator.h"

#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsScene>
#include <QTest>
#include <QKeyEvent>

ClickSimulator::ClickSimulator(QObject *parent) : 
QObject(parent)
{
}

void ClickSimulator::click()
{
    qDebug() << "click..." ;
    if (NULL != m_viewer)
    {
        const int x = qrand() % 300 , y = qrand() % 300 ;

		//QKeyEvent *event1 = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Space, Qt::NoModifier);
		//QCoreApplication::postEvent(m_viewer, event1);
		//QKeyEvent *event2 = new QKeyEvent(QKeyEvent::KeyRelease, Qt::Key_Space, Qt::NoModifier);
		//QCoreApplication::postEvent(m_viewer, event2);
		
		//press
		QMouseEvent *event1 = new QMouseEvent(QEvent::MouseButtonPress, QPointF(x,y), 
					Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
		QCoreApplication::postEvent(m_viewer, event1);
		//release	
		QMouseEvent *event2 = new QMouseEvent(QEvent::MouseButtonRelease, QPointF(x,y), 
					Qt::MouseButton::LeftButton, Qt::MouseButton::LeftButton, Qt::KeyboardModifier::NoModifier);
		QCoreApplication::postEvent(m_viewer, event2);

	}
}

