#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    setVisible(false);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::serverHosted(QString ip) {
    ui->label->setText("Local server hosted at: " + ip + ":2002");

}
