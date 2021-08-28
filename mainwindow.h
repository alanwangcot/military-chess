#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "preparewindow.h"
#include "gameboard.h"
#include "piece.h"
#include <QMouseEvent>
#include <sstream>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
//    void timeoutSlot();
    void remoteClientConnected();
    void closePreWin();

    void on_pushButton_clicked();
    void receiveMove();
    void sendMove(moveType mt);
    void drawPieces();
    void disableEventUntilMyTurn();


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    gameboard gb;
    void drawBoardInit();
//    void drawPieces();
    void mousePressEvent(QMouseEvent *event);
private:
    QLabel* boardDraw[5][12];
    preparewindow *preWin;
    bool firstClick = false;
    int pos1x, pos1y, pos2x, pos2y;
    bool myTurn;
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
        void moveSent();
        void mouseClicked(moveType mt);
};
#endif // MAINWINDOW_H
