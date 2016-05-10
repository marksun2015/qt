#ifndef CLICKSIMULATOR_H
#define CLICKSIMULATOR_H
#include <QObject>
#include <QDebug>
#include <QQuickView>

class ClickSimulator : public QObject
{
    Q_OBJECT
public:
	QQuickView* m_viewer; 
    explicit ClickSimulator(QObject *parent = 0);
    //void ClickSimulator(QQuickView* viewer);

public slots:
	void click();
	//void click(){
	//	qDebug() << "test" << m_viewer;
	//}
};
#endif // CLICKSIMULATOR_H
