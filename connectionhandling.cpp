#include "connectionhandling.h"
#include <QDebug>
#include <ctime>
#include <stdlib.h>
//#include <algorithm>

connectionhandling::connectionhandling(QObject *parent) : QObject(parent)
{
    gb.randPlacement();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            piece p = gb.getPiece(i,j);
            QString toAppend = QString::number(p.getRank()) + "," + QString::number(p.getSide()) + ",";
            toSend.append(toAppend);
        }
    }
    srand(time(NULL));
    int random = rand() % 100;
    if (random > 50) {
        toSend.append("0");
    }
    toSend.append("1");
    QObject::connect(readWriteSocket,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));
}

void connectionhandling::clientDisconnected() {
    emit clientDisconnect();
}

std::string connectionhandling::getToSend() {
    return toSend.toStdString();
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
