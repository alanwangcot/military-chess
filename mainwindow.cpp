#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setVisible(false);

    preWin = new preparewindow();
    preWin->setVisible(true);
    connect(preWin,SIGNAL(gotIP()),this, SLOT(closePreWin()));
    connect(preWin,SIGNAL(clientConnectSignalForMainWindow()),this,SLOT(remoteClientConnected()));
    firstClick = true;
    QObject::connect(this,SIGNAL(mouseClicked(moveType)),this,SLOT(sendMove(moveType)));
    QObject::connect(this,SIGNAL(mouseClicked(moveType)),this,SLOT(drawPieces()));
    QObject::connect(this,SIGNAL(moveSent()),this,SLOT(disableEventUntilMyTurn()));
//    QObject::connect(this->preWin->server->readWriteSocket,SIGNAL(readyRead()),this,SLOT(receiveMove()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closePreWin() {
    preWin->close();
}

void MainWindow::drawPieces() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if(gb.grid[i][j].getSide() == 0) {
                QPixmap qpm = QPixmap("/files/rsc/emptytile.png").scaled(boardDraw[i][j]->size());
                boardDraw[i][j]->setPixmap(qpm);
            }
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


void MainWindow::remoteClientConnected() {
    gb = preWin->server->getBoard();
    preWin->hide();
    drawBoardInit();
    this->show();
}

void MainWindow::drawBoardInit() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
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
        }
    }
    std::string sentInfo = preWin->server->getToSend();
    if (sentInfo[sentInfo.length() - 1] == 0) {
        myTurn = true;
    } else {
        myTurn = false;
    }
}

void MainWindow::on_pushButton_clicked()
{
    preWin->server->closeServer();
    this->close();
}

void MainWindow::disableEventUntilMyTurn() {
    qDebug() << "Mouse disabled!";
    myTurn = false;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
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
            MainWindow::mousePressEvent(event);
        }
    }


}

void MainWindow::sendMove(moveType mt)
{
    if (mt == movement) {
        QString qs = "m " + QString::number(pos1x) + "," + QString::number(pos1y) + "," + QString::number(pos2x) + QString::number(pos2y);
        preWin->server->readWriteSocket->write(qs.toUtf8());
         qDebug() << "move sent!";
        emit moveSent();

    }
    if (mt == reveal) {
        QString qs = "r " + QString::number(pos1x) + "," + QString::number(pos1y);
        preWin->server->readWriteSocket->write(qs.toUtf8());
         qDebug() << "move sent!";
        emit moveSent();
    }
    if (mt == timeout) {
        preWin->server->readWriteSocket->write("t");
    }
}

void MainWindow::receiveMove() {
    QString receivedMove;
    receivedMove = preWin->server->readWriteSocket->readAll();
    if (receivedMove.toStdString()[0] == 'r') {
        std::vector<std::string> receivedData;
        receivedData = MainWindow::split(receivedMove.toStdString().substr(2), ',');
        gb.grid[stoi(receivedData[0])][stoi(receivedData[1])].turnPiece();
    }
    if (receivedMove.toStdString()[0] == 'm') {
        std::vector<std::string> receivedData;
        receivedData = MainWindow::split(receivedMove.toStdString().substr(2), ',');
        gb.movePiece(stoi(receivedData[0]), stoi(receivedData[1]), stoi(receivedData[2]), stoi(receivedData[3]));
    }
    MainWindow::drawPieces();
    myTurn = true;
//    QTimer *timer = new QTimer(this);
//    timer->setInterval(20000);
//    connect(timer,SIGNAL(timeout()),this,SLOT(timeoutSlot()));
//    timer->start();
}

//void MainWindow::timeoutSlot() {
//    emit mouseClicked(timeout);
//}
