#include "myserver.h"
#include "mythread.h"

myserver::myserver(QObject *parent): QTcpServer(parent) {

}

void myserver::startServer() {
    int port = 2002;
    if (!this->listen(QHostAddress::Any,port)) {

    } else {

    }
}

void myserver::incomingConnection(qintptr socketDescriptor) {
    mythread *thread = new mythread(socketDescriptor, this);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}
