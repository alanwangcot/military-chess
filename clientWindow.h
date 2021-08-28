#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "gameboard.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <QTcpSocket>
#include <QLabel>



namespace Ui {
class clientWindow;
}

class clientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientWindow(QWidget *parent = 0);
    ~clientWindow();
   void mousePressEvent(QMouseEvent *event);
    void connectHost(QString ip);
//    void sendMove(int pos1x, int pos1y, int pos2x, int pos2y);
//    void sendMove(int posx, int posy);
private:
    Ui::clientWindow *ui;
    gameboard gb;
    QTcpSocket *socket;
    int pos1x, pos1y, pos2x, pos2y;
    bool firstClick;
//    piece p1, p2;
    QLabel* boardDraw[5][12];
    bool myTurn = true;

public slots:
//    void connectedToHost();
//    void victory();
//    void receiveSide(int side);
//    void receiveOpponentMove(gameboard::moveType mt);
//    void myTurn();
    void drawPieces();
    void sendMove(moveType mt);

private slots:
    void receiveData();
    void disableEventUntilMyTurn();

    void on_pushButton_clicked();

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
    void moveSent();
    void mouseClicked(moveType mt);
};

#endif // CLIENTWINDOW_H
