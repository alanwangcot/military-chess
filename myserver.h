#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
//#include <QTcpSocket>

class myserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit myserver(QObject *parent = 0);
    void startServer();

signals:



public slots:
//    void newConnection();
protected:
     void incomingConnection(qintptr socketDescriptor);
};

#endif // MYSERVER_H
