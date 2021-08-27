#include "mythread.h"

mythread::mythread(qintptr ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = ID;
}

void mythread::run() {
    socket = new QTcpSocket;
    if (!socket->setSocketDescriptor(this->socketDescriptor)) {
        emit error(socket->error());
        return;


    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    exec();
    }
}

void mythread::readyRead() {
    QByteArray data = socket->readAll();
    socket->write(data);
}

void mythread::disconnected() {
    socket->deleteLater();
    exit(0);
}
