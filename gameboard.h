#include <vector>
//#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <algorithm>

#include "piece.h"
//#include "dfsHelper.h"

#ifndef GAMEBOARD_H
#define GAMEBOARD_H


enum moveType {
    movement = 0,
    reveal = 1
};


class gameboard {
private:


    std::vector<piece> addQueue;
//    bool redWin. blueWin;

//    bool DFSHelper(int x1, int y1, int x2, int y2)  {

//    }
public:
    piece grid[5][12];
    bool safeTile[5][12];
    bool railTile[5][12];
    int lastRevealedSide = 0;
    gameboard();
    void randPlacement();

    bool movePiece(int pos1x, int pos1y, int pos2x, int pos2y);

    bool redCanTakeBlueFlag();
    bool blueCanTakeRedFlag();

    bool moveFlip(int posx, int posy);

    piece getPiece(int posx, int posy);

    bool redVictory();
    bool blueVictory();
};





/*Ranks:
 * 0 - 工兵 *3
 * 1 - 排长 *3
 * 2 - 连长 *3
 * 3 - 营长 *2
 * 4 - 团长 *2
 * 5 - 旅长 *2
 * 6 - 师长 *2
 * 7 - 军长 *2
 * 8 - 司令 *1
 * 9 - 炸弹 *2
 * 10 - 军旗 *1
 * 11 - 地雷 *3
 **/




#endif // GAMEBOARD_H

