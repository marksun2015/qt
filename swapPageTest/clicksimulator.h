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
	//int count;
	//int wait;
    explicit ClickSimulator(QObject *parent = 0);

public slots:
	void click();
};
#endif // CLICKSIMULATOR_H
