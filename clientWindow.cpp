#include "clientwindow.h"
#include "ui_clientWindow.h"
#include <QString>
#include <QObject>
#include <QPushButton>
#include "gameboard.h"
#include "piece.h"
#include <QHostAddress>
#include <iostream>
#include <regex>
#include <QMouseEvent>

clientWindow::clientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientWindow)
{
    ui->setupUi(this);
    setVisible(true);
//    ui->label->hide();
//    QPixmap pm = QPixmap(":/files/rsc/emptyboardwithbgrd.png").scaled(737,1024);
//    QPalette p(this->palette());
//    p.setBrush(QPalette::Window, QBrush(pm));
//    this->setPalette(p);
//      QLabel* boardDraw[5][12];
    firstClick = false;
    QObject::connect(this,SIGNAL(mouseClicked(moveType)),this,SLOT(sendMove(moveType)));
    QObject::connect(this,SIGNAL(mouseClicked(moveType)),this,SLOT(drawPieces()));
    QObject::connect(this,SIGNAL(moveSent()),this,SLOT(disableEventUntilMyTurn()));
}

clientWindow::~clientWindow()
{
    delete ui;
}

void clientWindow::disableEventUntilMyTurn() {
    qDebug() << "Mouse disabled!";
    myTurn = false;
}


void clientWindow::mousePressEvent(QMouseEvent *event) {
    if  (myTurn){
        if(event->button() == Qt::LeftButton) {
    //        qDebug() << "mouse click registered";
            if (firstClick) {
                if (event->x() > 20 && event->x() < 120) {
                    pos1x = 0;
                }
                if (event->x() >170 && event->x() < 270) {
                    pos1x = 1;
                }
                if (event->x() > 320 && event->x() < 420) {
                    pos1x = 2;
                }
                if (event->x() > 470 && event->x() < 570) {
                    pos1x = 3;
                }
                if (event->x() > 615 && event->x() < 715) {
                    pos1x = 4;
                }
                if(event->y() > 20 && event->y() < 70) {
                    pos1y = 0;
                }
                if(event->y() > 90 && event->y() < 140) {
                    pos1y = 1;
                }
                if(event->y() > 160 && event->y() < 210) {
                    pos1y = 2;
                }
                if(event->y() > 230 && event->y() < 280) {
                    pos1y = 3;
                }
                if(event->y() > 300 && event->y() < 350) {
                    pos1y = 4;
                }
                if(event->y() > 370 && event->y() < 420) {
                    pos1y = 5;
                }
                if(event->y() > 595 && event->y() < 645) {
                    pos1y = 6;
                }
                if(event->y() > 665 && event->y() < 715) {
                    pos1y = 7;
                }
                if(event->y() > 735 && event->y() < 785) {
                    pos1y = 8;
                }
                if(event->y() > 805 && event->y() < 855) {
                    pos1y = 9;
                }
                if(event->y() > 880 && event->y() < 930) {
                    pos1y = 10;
                }
                if(event->y() > 950 && event->y() < 1000) {
                    pos1y = 11;
                }
                firstClick = false;
                if (!gb.grid[pos1x][pos1y].isRevealed() && !gb.safeTile[pos1x][pos1y]) {
                    gb.grid[pos1x][pos1y].turnPiece();
                    firstClick = true;
                    emit mouseClicked(reveal);
                }

            }

            if (!firstClick) {
                if (event->x() > 20 && event->x() < 120) {
                    pos2x = 0;
                }
                if (event->x() >170 && event->x() < 270) {
                    pos2x = 1;
                }
                if (event->x() > 320 && event->x() < 420) {
                    pos2x = 2;
                }
                if (event->x() > 470 && event->x() < 570) {
                    pos2x = 3;
                }
                if (event->x() > 615 && event->x() < 715) {
                    pos2x = 4;
                }
                if(event->y() > 20 && event->y() < 70) {
                    pos2y = 0;
                }
                if(event->y() > 90 && event->y() < 140) {
                    pos2y = 1;
                }
                if(event->y() > 160 && event->y() < 210) {
                    pos2y = 2;
                }
                if(event->y() > 230 && event->y() < 280) {
                    pos2y = 3;
                }
                if(event->y() > 300 && event->y() < 350) {
                    pos2y = 4;
                }
                if(event->y() > 370 && event->y() < 420) {
                    pos2y = 5;
                }
                if(event->y() > 595 && event->y() < 645) {
                    pos2y = 6;
                }
                if(event->y() > 665 && event->y() < 715) {
                    pos2y = 7;
                }
                if(event->y() > 735 && event->y() < 785) {
                    pos2y = 8;
                }
                if(event->y() > 805 && event->y() < 855) {
                    pos2y = 9;
                }
                if(event->y() > 880 && event->y() < 930) {
                    pos2y = 10;
                }
                if(event->y() > 950 && event->y() < 1000) {
                    pos2y = 11;
                }
                firstClick = true;
                if(gb.movePiece(pos1x, pos1y, pos2x, pos2y)) {
                    emit mouseClicked(movement);
                }
            }
        } else {
            clientWindow::mousePressEvent(event);
        }
    }


}

void clientWindow::sendMove(moveType mt)
{
    if (mt = movement) {
        QString qs = "moved " + QString::number(pos1x) + "," + QString::number(pos1y) + "," + QString::number(pos2x) + QString::number(pos2y);
        socket->write(qs.toUtf8());
         qDebug() << "move sent!";
        emit moveSent();

    }
    if (mt = reveal) {
        QString qs = "revealed " + QString::number(pos1x) + "," + QString::number(pos1y);
        socket->write(qs.toUtf8());
         qDebug() << "move sent!";
        emit moveSent();
    }

}


void clientWindow::connectHost(QString ip) {
    socket = new QTcpSocket;
    socket->connectToHost(QHostAddress(ip),2002);
    QObject::connect(this->socket,SIGNAL(readyRead()),this,SLOT(receiveData()));
    if (socket->QAbstractSocket::waitForConnected(3000)) {
        emit connected();
    } else {
//        emit socket->error();
    }
}

void clientWindow::drawPieces() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if(gb.grid[i][j].isRevealed()) {
                int side = 1;
                if (gb.grid[i][j].getSide() == -1) {
                    side = 2;
                }
                QPixmap qpm = QPixmap(":/files/rsc/" + QString::number(gb.grid[i][j].getRank()) + "-" + QString::number(side)).scaled(boardDraw[i][j]->size());
                boardDraw[i][j]->setPixmap(qpm);
            }
        }
    }
}

void clientWindow::receiveData() {
    QString received;
    received = this->socket->readAll();
    qDebug() << "initial state received";
//    qDebug() << received;
//    ui->label_2->setText(received);
//    std::string newPiece = "";
    std::vector<std::string> receivedPieceData;
    receivedPieceData = clientWindow::split(received.toStdString(), ',');
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            piece p(stoi(receivedPieceData[0]),stoi(receivedPieceData[1]));
            gb.grid[i][j] = p;

            boardDraw[i][j] = new QLabel(this);
            boardDraw[i][j]->setText("");
            int yLoc = 20 + j* 70;
            if (j >= 6) yLoc += 155;
            int xLoc = 20 + i*150;
            if(i == 4) xLoc = 615;
            boardDraw[i][j]->setGeometry(xLoc, yLoc, 100, 50);
            QPixmap pm = QPixmap(":/files/rsc/unrevealed.png").scaled(boardDraw[i][j]->size());
            boardDraw[i][j]->setPixmap(pm);
            boardDraw[i][j]->setVisible(true);
            if (gb.safeTile[i][j]) {
                boardDraw[i][j]->setVisible(false);
            }



//            qDebug() << QString::number(p.getRank()) + "," + QString::number(p.getSide());
            receivedPieceData.erase(receivedPieceData.begin());
            receivedPieceData.erase(receivedPieceData.begin());
        }
    }
}

void clientWindow::on_pushButton_clicked()
{
    socket->disconnectFromHost();
    this->close();
}

