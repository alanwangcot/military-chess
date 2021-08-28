#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "preparewindow.h"
#include "gameboard.h"
#include "piece.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void checkTile() {

    }
    void remoteClientConnected();
    void closePreWin();

    void on_pushButton_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    gameboard gb;
    void drawBoardInit();
    void drawPieces();
private:
    QLabel* boardDraw[5][12];
    preparewindow *preWin;
};
#endif // MAINWINDOW_H
