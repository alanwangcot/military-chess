#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QTcpSocket>
#include <QObject>
#include <QThread>
#include <QDebug>

class mythread : public QThread
{
    Q_OBJECT


private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
public:
    explicit mythread(qintptr ID, QObject *parent = nullptr);
//    ~mythread();
    void run();
signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();
};

#endif // MYTHREAD_H
