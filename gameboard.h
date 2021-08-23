#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "piece.h"

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#endif // GAMEBOARD_H

class gameboard {
private:
    piece grid[5][12];
    std::vector<piece> addQueue;
public:
    gameboard() {
        for (int i = -1; i <=1; i+=2) {
            piece p(0, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(1, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(2, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(3, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(4, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(5, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(6, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(7, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            p = piece(8, i);
            addQueue.push_back(p);
            p = piece(9, i);
            addQueue.push_back(p);
            p = piece(10, i);
            addQueue.push_back(p);
            p = piece(11, i);
            addQueue.push_back(p);
            addQueue.push_back(p);
            addQueue.push_back(p);
        }
    }
    void randPlacement() {
        using namespace std;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 5; j++) {

                grid[i][j].printPiece();
            }
             cout << endl;
        }
        srand(time(NULL));
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 12; j++) {

                if (i == 1 || i == 4) {
                    if (j == 2 || j == 4 || j == 7 || j == 9) {
                        continue;
                    }
                }
                if (i == 2 && (j == 3 || j == 8)) {
                    continue;
                }
                int randInd = rand() % (addQueue.size());
//                cout << randInd;
                grid[i][j] = addQueue[randInd];
//                grid[i][j].printPiece();
//                auto toRemove = addQueue.begin() + randInd - 1;
                addQueue.erase(addQueue.begin() + randInd);
            }
        }
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 5; j++) {

                grid[i][j].printPiece();
            }
             cout << endl;
        }
    }


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
