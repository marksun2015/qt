#include <QQueue>
#include <QDebug>
#include <string>

#include <iostream>
#include <QList>
#include <QTextStream>
#include <algorithm>

#include <QtCore>

using namespace std;

typedef struct _dbus_command {  
    QString method;
    QList<QVariant> argumentList;
} dbus_command;   


QQueue<dbus_command> queue;

class Dbus_command_thread : public QThread
{
    private:
        void run();
};

void send_command(const QString &method, const QList<QVariant> &args)
{
    //cout <<"method of the List :"<< method.toString() <<endl;
    qDebug() <<"method of the List :"<< method <<endl;

    //cout <<"size of the List :"<< args.size() <<endl;
    for(int i = 0; i< args.size(); i++)
        qDebug() << args.at(i).toString();
}

//thread_fun(QQueue<dbus_command> &commands)
void Dbus_command_thread::run()
{
    QQueue<dbus_command> commands = queue;
    do{
        while (!commands.isEmpty()) {
            //qDebug() << commands.head().method; 
            send_command(commands.head().method, commands.head().argumentList);
            commands.dequeue();
        }
        QThread::msleep(500);
        qDebug() << "Thread loop"; 
    } while(1);
}

int main(int argc, char * argv[])
{
    QCoreApplication app(argc, argv);

    dbus_command cmd1;
    cmd1.method = "commmand1";
    cmd1.argumentList << 1 << 2 << 3;
    queue.enqueue(cmd1);

    dbus_command cmd2;
    cmd2.method = "commmand2";
    QString url = "http://www.google.com";
    cmd2.argumentList << url.toUtf8().constData() << 2 << 3;
    queue.enqueue(cmd2);

    Dbus_command_thread *thread = new Dbus_command_thread();
    thread->start();

    qDebug() << "app.exec...";
    return app.exec();
}

/*
    queue.enqueue("command4");
    while (!queue.isEmpty())
    {
        QString s = queue.head();
        
        QString command;
        command = s.split(" ").at(0);

        if(command.compare("command1") == 0){
            qDebug() << "split: " << s.split(" ").at(1);
            qDebug() << "split: " << s.split(" ").at(2);
            qDebug() << "split: " << s.split(" ").at(3);
        }
        queue.dequeue();
    }
*/

