#include "connectionhandling.h"
#include <QDebug>

connectionhandling::connectionhandling(QObject *parent) : QObject(parent)
{
    gb.randPlacement();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            piece p = gb.getPiece(i,j);
            QString toAppend = QString::number(p.getRank()) + "," + QString::number(p.getSide()) + ",";
            toSend.append(toAppend);
        }
    }

}

void connectionhandling::initServer() {
    this->listenSocket = new QTcpServer;
    this->listenSocket->listen(QHostAddress::Any, 2002);
//    QString localHostName = QHostInfo::localHostName();
//    QHostInfo info = QHostInfo::fromName(localHostName);
//    QString serverIP;
//    foreach(QHostAddress adr, info.addresses()) {
//        if(adr.protocol() == QAbstractSocket::IPv4Protocol) {
//            serverIP = adr.toString();
//        }
//    }
    QObject::connect(this->listenSocket,SIGNAL(newConnection()),this,SLOT(acceptConnection()));

}

void connectionhandling::acceptConnection() {
    this->readWriteSocket = this->listenSocket->nextPendingConnection();
    QObject::connect(this->readWriteSocket,SIGNAL(readyRead()),this,SLOT(receivePacket()));
    emit clientConnected();
}

void connectionhandling::receivePacket() {
    QString info;
    info = readWriteSocket->readAll();
}

void connectionhandling::sendInitialState() {
//    qDebug() << "initial state sent";
//    qDebug() << toSend;
    readWriteSocket->write(toSend.toUtf8());
    emit initialStateSent();
}

gameboard connectionhandling::getBoard() {
    return gb;
}

void connectionhandling::closeServer() {
    this->listenSocket->close();
}
