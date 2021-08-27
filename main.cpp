#include "mainwindow.h"
#include "gameboard.h"
#include "myserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{

//    gameboard gb;
//    gb.randPlacement();


    QApplication a(argc, argv);
    MainWindow w;
//    myserver server;
//    w.show();
    return a.exec();
}
