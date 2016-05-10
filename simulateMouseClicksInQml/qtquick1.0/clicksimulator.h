#ifndef CLICKSIMULATOR_H
#define CLICKSIMULATOR_H

#include <QObject>

class QmlApplicationViewer;

class ClickSimulator : public QObject
{
    Q_OBJECT
    QmlApplicationViewer* m_viewer;
public:
    explicit ClickSimulator(QmlApplicationViewer* viewer, QObject *parent = 0);

public slots:
    void click();    
};

#endif // CLICKSIMULATOR_H
