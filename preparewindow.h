#ifndef PREPAREWINDOW_H
#define PREPAREWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDialog>
#include "dialog.h"
#include "ui_dialog.h"
#include "connectionhandling.h"
#include "dialogdisconnected.h"
#include "ui_dialogdisconnected.h"

QT_BEGIN_NAMESPACE
namespace Ui { class preparewindow; }
QT_END_NAMESPACE

class preparewindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit preparewindow(QWidget *parent = 0);
    ~preparewindow();
     connectionhandling *server;
    void initial();

signals:
    void serverStarted(QString ip);
    void gotIP();
//    void clientConnect();
    void clientConnectSignalForMainWindow();


private:
    Ui::preparewindow *ui;
//    bool b = false;
    QString connectIP = "";
    Dialog *diag;


public slots:
//    void stateChanged(bool checked);
    void on_connectServerButton_clicked();
    void gotIPSignal(QString ip);
    void clientDisconnected();

private slots:
    void on_createServerButton_clicked();
    void serverClientConnected();
};

#endif // PREPAREWINDOW_H
