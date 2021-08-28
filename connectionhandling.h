#ifndef CONNECTIONHANDLING_H
#define CONNECTIONHANDLING_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QString>
#include <QDataStream>
#include <QTimer>
#include "gameboard.h"
#include "piece.h"

class connectionhandling : public QObject
{
    Q_OBJECT
public:
    explicit connectionhandling(QObject *parent = nullptr);
//    ~connectionhandling();
    QTcpServer *listenSocket;
    void initServer();
    void sendInitialState();
    gameboard getBoard();

public slots:
    void acceptConnection();
    void receivePacket();
//    void pieceSelected();
//    void makeMove();
//    void gameOver();
////  void restartOrExit();

signals:
    void initialStateSent();
    void clientConnected();

private:
//    QTcpServer *listenSocket;
    QTcpSocket *readWriteSocket;
    gameboard gb;
    QString toSend;
//    bool isOccupied;
//    bool isReady;
//    bool entered[2];

//    QDataStream::Version myQtVersion;
//    QByteArray Prepared(int side);
//    QByteArray

};

#endif // CONNECTIONHANDLING_H
