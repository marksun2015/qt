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

#include "../include/clicksimulator.h"

QQmlEngine * theQmlEngine(0);
QString r_totaltime;
int qmlloaded=1;

#define WIDTH 1024
#define HEIGHT 600

class Swappage
    : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString totaltime READ totaltime NOTIFY totaltime_Change)
	Q_PROPERTY(int myPrty READ GetMyProperty WRITE SetMyProperty NOTIFY myPropertyValueChanged)

public:
    Swappage(QQuickItem * root_window)
        :root_window_(root_window)
    {

    }

	QString totaltime() 
	{
		return r_totaltime;
	}	
	
	int GetMyProperty()
	{

	}
	void SetMyProperty(int value)
	{
		qmlloaded=value;
		emit myPropertyValueChanged();
	}

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
	
	QQuickItem *root_window = new QQuickItem(view.rootObject());
	root_window->setSize(QSizeF(WIDTH, HEIGHT)); 
	Swappage swappage(root_window);
	view.engine()->rootContext()->setContextProperty("swappage",&swappage);
	
	//view.setSource(QUrl("mainclick.qml"));
	view.setSource(QString("qrc:/qml/mainclick.qml")); 
	view.setSurfaceType(QSurface::OpenGLSurface);
	view.rootObject()->setSize(QSizeF(WIDTH, HEIGHT));

	QApplication::setAttribute(Qt::AA_UseOpenGLES);                  
	theQmlEngine = new QQmlEngine(&app);

#if 1
	ClickSimulator *sim = new ClickSimulator();
	sim->m_viewer=&view;
	QTimer::singleShot(200, sim, SLOT(click()));
#endif

	//QTimer *timer=new QTimer();
	//QObject::connect(timer,SIGNAL(timeout()),sim,SLOT(click())); 
	//timer->start(0);

    view.show();
    return app.exec();
}

#include "main.moc"
