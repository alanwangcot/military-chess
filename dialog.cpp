#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <iostream>
#include <string>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setVisible(false);
    initial();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initial() {
    QPixmap pm = QPixmap(":/files/rsc/chessboardbackground.jpg").scaled(this->size());
    QPalette p(this->palette());
    p.setBrush(QPalette::Window, QBrush(pm));
    this->setPalette(p);
}

//QString Dialog::getIP(){
//    std::cout << "getIP called";
//    return input;
//}

void Dialog::on_ConnectButton_clicked()
{
    input = ui->lineEdit->text();
    emit Dialog::connectButtonClicked(input);
    this->hide();
//    std::cout << inputIP.toStdString();
}


void Dialog::on_CancelButton_clicked()
{
    this->close();
}

//void Dialog::connectButtonClicked(QString IP);

