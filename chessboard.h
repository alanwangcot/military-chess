#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "tile.h"
#include "piece.h"
#include <vector>
#include <stdlib.h>

class chessboard {
private:

    std::vector<tile> tiles;
    std::vector<piece> pieces;

public:
    chessboard() {
//        int counter = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 5; j++) {
                tile t(i, j);
                tiles.push_back(t);
            }
        }
        for (int i = 0; i < 2; i++) {
            piece p(-2, i);
            pieces.push_back(p);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(-1, i);
            pieces.push_back(p);
            p = piece(0, i);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(1, i);
            pieces.push_back(p);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(2, i);
            pieces.push_back(p);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(3, i);
            pieces.push_back(p);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(4, i);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(5, i);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(6, i);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(7, i);
            pieces.push_back(p);
            pieces.push_back(p);
            p = piece(8, i);
            pieces.push_back(p);
            p = piece(9, i);
            pieces.push_back(p);

        }
    }

    void randomInit() {
        srand(time(NULL));
        int counter = 0;
        while (pieces.size() != 0)  {
            int randInd = rand() % (pieces.size() - 1);
            if(tiles[counter].isSafe()) {
                counter++;
            }
            tiles[counter].setPiece(pieces[randInd]);
        }

    }
};

#endif // CHESSBOARD_H


/* Ranks:
 * -2：地雷 *3
 * -1: 军旗 *1
 * 0： 炸弹 *2
 * 1：工兵 *3
 * 2：排长 *3
 * 3：连长 *3
 * 4：营长 *2
 * 5：团长 *2
 * 6：旅长 *2
 * 7：师长 *2
 * 8：军长 *1
 * 9：司令 *1
 */
