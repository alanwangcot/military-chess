#ifndef PIECE_H
#define PIECE_H

#include <QObject>
#include <QWidget>

class piece  {
private:
    int rank;
    int side;
    bool revealed;
    bool movable;
public:
    piece() {
        rank = -3;
        side = -1;
        revealed = false;
        movable = false;
    }
    piece(int _rank, int _side) {
        rank = _rank;
        side = _side;
        revealed = false;
        movable = true;
        if (rank == -2 || rank == -1) {
            movable = false;
        }
    }
    bool isRevealed() {
        return revealed;
    }
    int getRank() {
        return rank;
    }

};

#endif // PIECE_H


/* Ranks:
 * -2：地雷
 * -1: 军旗
 * 0： 炸弹
 * 1：工兵
 * 2：排长
 * 3：连长
 * 4：营长
 * 5：团长
 * 6：旅长
 * 7：师长
 * 8：军长
 * 9：司令
 */
