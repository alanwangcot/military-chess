#include "dialogdisconnected.h"
#include "ui_dialogdisconnected.h"

DialogDisconnected::DialogDisconnected(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDisconnected)
{
    ui->setupUi(this);
}

DialogDisconnected::~DialogDisconnected()
{
    delete ui;
}
