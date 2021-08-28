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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closePreWin() {
    preWin->close();
}

void MainWindow::remoteClientConnected() {
    gb = preWin->server->getBoard();
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
}

void MainWindow::on_pushButton_clicked()
{
    preWin->server->closeServer();
}

