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

#pragma warning(default: 4512)


class MyClass : public QObject
{
	Q_OBJECT
	public slots:
	void cppSlot(const QVariant &v) {
		qDebug() << "Called the C++ slot with value:" << v;
		QQuickItem *item = qobject_cast<QQuickItem*>(v.value<QObject*>());
		qDebug() << "Item dimensions:" << item->width() << item->height();
	}
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	QQuickView view(QUrl::fromLocalFile("myitem.qml"));
	QObject *item = view.rootObject();
	MyClass myClass;
	QObject::connect(item, SIGNAL(qmlSignal(QVariant)),
			&myClass, SLOT(cppSlot(QVariant)));

		 
    view.show();
    return app.exec();
}

#include "main.moc" // Required.
