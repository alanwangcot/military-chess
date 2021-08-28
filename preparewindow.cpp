#include "preparewindow.h"
#include "ui_preparewindow.h"
#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>
#include <QDialog>
#include <QDebug>
#include <QNetworkInterface>
#include <QString>
#include "myserver.h"
#include "dialog2.h"
#include "ui_dialog2.h"
#include "connectionhandling.h"
#include "clientWindow.h"
#include "ui_clientwindow.h"


preparewindow::preparewindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::preparewindow)
{
        initial();
        diag = new Dialog();
//        connect(diag,SIGNAL(connectButtonClicked(QString ip)),this,SLOT(gotIPSignal(QString ip)));
        QObject::connect(diag,SIGNAL(connectButtonClicked(QString)), this, SLOT(gotIPSignal(QString)));

}

preparewindow::~preparewindow() {
    delete ui;
}

void preparewindow::initial() {
    ui->setupUi(this);
    ui->connectServerButton->setEnabled(true);
//    ui->connectServerButton->setCheckable(true);
//    ui->connectServerButton->setChecked(false);
    ui->createServerButton->setEnabled(true);
//    ui->createServerButton->setCheckable(true);
//    ui->createServerButton->setChecked(false);
    QPixmap pm = QPixmap(":/files/rsc/chessboardbackground.jpg").scaled(this->size());
    QPalette p(this->palette());
    p.setBrush(QPalette::Window, QBrush(pm));
    this->setPalette(p);
}

void preparewindow::on_connectServerButton_clicked()
{

//    Dialog diag;
    diag->setVisible(true);
//    diag->Dialog::getIP();


}

void preparewindow::gotIPSignal(QString ip) {
    connectIP = ip;

//    std::cout << connectIP.toStdString();
//    ui->text->clear();
//    ui->text->setText(ip);

    diag->close();
    this->setVisible(false);
    clientWindow *cw = new clientWindow;
    cw->connectHost(ip);

}

void preparewindow::on_createServerButton_clicked()
{
    QString ipv4adr = "";
    QList<QHostAddress> list = QNetworkInterface::allAddresses();

     for(int nIter=0; nIter<list.count(); nIter++)

      {
          if(!list[nIter].isLoopback())
              if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol )
            ipv4adr = list[nIter].toString();

      }

    server = new connectionhandling;
    server->initServer();
    Dialog2 *d2 = new Dialog2();
//    d2->setVisible(false);
    d2->serverHosted(ipv4adr);
    d2->setVisible(true);
    ui->createServerButton->setEnabled(false);
    ui->connectServerButton->setEnabled(false);
    QObject::connect(server,SIGNAL(clientConnected()),this,SLOT(serverClientConnected()));
}

void preparewindow::serverClientConnected() {
    this->server->sendInitialState();
}
