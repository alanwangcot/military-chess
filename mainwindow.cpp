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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::closePreWin() {
    preWin->close();
}
