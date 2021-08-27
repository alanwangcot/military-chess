#include "clientwindow.h"
#include "ui_clientwindow.h"
#include <QString>
#include <QObject>
#include <QPushButton>
#include "gameboard.h"
#include "piece.h"
#include <QHostAddress>
#include <iostream>
#include <regex>

clientWindow::clientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientWindow)
{
    ui->setupUi(this);
    setVisible(true);
    ui->label->hide();
}

clientWindow::~clientWindow()
{
    delete ui;
}

void clientWindow::connectHost(QString ip) {
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip),2002);
    QObject::connect(this->socket,SIGNAL(readyRead()),this,SLOT(receiveData()));
}

void clientWindow::receiveData() {
    QString received;
    received = this->socket->readAll();
//    qDebug() << "initial state received";
//    qDebug() << received;
//    ui->label_2->setText(received);
//    std::string newPiece = "";
    std::vector<std::string> receivedPieceData;
    receivedPieceData = clientWindow::split(received.toStdString(), ',');
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            piece p(stoi(receivedPieceData[0]),stoi(receivedPieceData[1]));
            gb.grid[i][j] = p;

//            qDebug() << QString::number(p.getRank()) + "," + QString::number(p.getSide());
            receivedPieceData.erase(receivedPieceData.begin());
            receivedPieceData.erase(receivedPieceData.begin());
        }
    }
}
