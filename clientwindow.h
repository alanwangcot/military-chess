#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "gameboard.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <QTcpSocket>

namespace Ui {
class clientWindow;
}

class clientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientWindow(QWidget *parent = 0);
    ~clientWindow();

    void connectHost(QString ip);

private:
    Ui::clientWindow *ui;
    gameboard gb;
    QTcpSocket *socket;

public slots:
//    void connectedToHost();
//    void victory();
//    void receiveSide(int side);
//    void receiveOpponentMove(gameboard::moveType mt);
//    void myTurn();

private slots:
    void receiveData();
private:
    std::vector<std::string> &split(const std::string &s, char delim,std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {

                elems.push_back(item);

        }
        return elems;
    }


    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }

signals:
    void connected();
};

#endif // CLIENTWINDOW_H
