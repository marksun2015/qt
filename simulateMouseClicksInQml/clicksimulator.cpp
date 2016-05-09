/*
 * 	http://stackoverflow.com/questions/7517700/how-to-simulate-mouse-clicks-in-qml
 */

#include "clicksimulator.h"
#include "qmlapplicationviewer.h"

#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsScene>
#include <QTest>

#define _WIN32_WINNT 0x0501
#define WINVER 0x0501
//#include "Windows.h"


ClickSimulator::ClickSimulator(QmlApplicationViewer* viewer, QObject *parent) :
QObject(parent)
, m_viewer(viewer)
{
}

void ClickSimulator::click()
{
    if (NULL != m_viewer)
    {
        const int x = qrand() % 1024 , y = qrand() % 600 ;
      	bool isSent;

		QGraphicsSceneMouseEvent pressEvent(QEvent::GraphicsSceneMousePress);
		pressEvent.setScenePos(QPointF(x, y));
		pressEvent.setButton(Qt::LeftButton);
		pressEvent.setButtons(Qt::LeftButton);
		//QApplication::sendEvent(m_viewer->scene(), &pressEvent);
        isSent = QApplication::sendEvent(m_viewer->scene(), &pressEvent);
        qDebug() << "isSent press: " << isSent;

		QGraphicsSceneMouseEvent releaseEvent(QEvent::GraphicsSceneMouseRelease);
		releaseEvent.setScenePos(QPointF(x, y));
		releaseEvent.setButton(Qt::LeftButton);
		releaseEvent.setButtons(Qt::LeftButton);
		isSent = QApplication::sendEvent(m_viewer->scene(), &releaseEvent);
        qDebug() << "isSent Release: " << isSent;
#if 0
        {
           QMouseEvent pressEvent(QEvent::MouseButtonPress, QPoint(x, y), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
//            QMouseEvent pressEvent(
//                QEvent::MouseButtonPress, 
//                QPoint(x, y),
//                Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
           const bool isSent = QApplication::sendEvent(m_viewer->scene(), &pressEvent);
           qDebug() << "'Press' at (" << x << "," << y << ") successful? " << isSent;
        }

        {
            QGraphicsSceneMouseEvent pressEvent(QEvent::GraphicsSceneMousePress);
            pressEvent.setScenePos(QPointF(x, y));
            pressEvent.setButton(Qt::LeftButton);
            pressEvent.setButtons(Qt::LeftButton);

            QGraphicsItem* item = m_viewer->itemAt(x, y);
            const bool isSent = m_viewer->scene()->sendEvent(item, &pressEvent);
            //const bool isSent = QApplication::sendEvent(m_viewer->scene(), &pressEvent);
            qDebug() << "'Press' at (" << x << "," << y << ") successful? " << isSent;
        }
#endif

#if 0
        // This platform specific code works...
        {
            const double fScreenWidth = ::GetSystemMetrics( SM_CXSCREEN )-1; 
            const double fScreenHeight = ::GetSystemMetrics( SM_CYSCREEN )-1; 
            const double fx = x*(65535.0f/fScreenWidth);
            const double fy = y*(65535.0f/fScreenHeight);

            INPUT inp[3];
            inp[0].type = INPUT_MOUSE;

            MOUSEINPUT & mi = inp[0].mi;
            mi.dx = fx;
            mi.dy = fy;
            mi.mouseData = 0;
            mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
            mi.time = 0;
            mi.dwExtraInfo = 0;

            inp[1] = inp[0];
            inp[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

            inp[2] = inp[0];
            inp[2].mi.dwFlags = MOUSEEVENTF_LEFTUP;

            SendInput(3, inp, sizeof(INPUT));
        }
#endif
    }
}
