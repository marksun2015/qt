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

#include <QThread>
#include <QTime>
#include <QDebug>
#include <QtCore>
#include <QObject>

#include <QFile>

#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsScene>

#include "clicksimulator.h"

#pragma warning(default: 4512)

QQmlEngine * theQmlEngine(0);
QString r_totaltime;
int qmlloaded=1;

class CPUrate
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString totaltime READ totaltime NOTIFY totaltime_Change)
	Q_PROPERTY(int myPrty READ GetMyProperty WRITE SetMyProperty NOTIFY myPropertyValueChanged)

public:
    CPUrate(QQuickItem * root_window)
        :root_window_(root_window)
    {

    }

	QString totaltime() 
	{
		//qWarning() << "cpu usage:"<< r_cpu_usage;
		return r_totaltime;
	}	
	
	int GetMyProperty()
	{
		//qDebug() << "get";
	}
	void SetMyProperty(int value)
	{
		qmlloaded=value;
		//qDebug() << "qmlloaded" << qmlloaded;
		emit myPropertyValueChanged();
	}

#if 0
	int cursory();

	void setCursory(int y)
	{
	
	}
#endif

    std::vector<QQuickItem *> buttons_;
    QQuickItem * root_window_;
signals:
	void totaltime_Change();
	void myPropertyValueChanged();
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	QQuickView view;
	view.setSource(QUrl("mainscreen.qml"));
	view.setSurfaceType(QSurface::OpenGLSurface);
	view.rootObject()->setSize(QSizeF(1024, 600));

	ClickSimulator *sim = new ClickSimulator();
	sim->m_viewer=&view;
	QTimer::singleShot(200, sim, SLOT(click()));

	QApplication::setAttribute(Qt::AA_UseOpenGLES);                  
	theQmlEngine = new QQmlEngine(&app);

	QQuickItem *root_window = new QQuickItem(view.rootObject());
	root_window->setSize(QSizeF(1024, 600)); 
	CPUrate cpurate(root_window);
	view.engine()->rootContext()->setContextProperty("cpurate",&cpurate);

	//QTimer *timer=new QTimer();
	//QObject::connect(timer,SIGNAL(timeout()),sim,SLOT(click())); 
	//timer->start(0);

    view.show();
    return app.exec();
}

#include "main.moc"
