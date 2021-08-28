#include "gameboard.h"

gameboard::gameboard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
               railTile[i][j] = false;
               safeTile[i][j] = false;
            if (j == 1 || j == 5 || j == 6 || j == 10) {
                railTile[i][j] = true;
            }
            if (i == 0 || i == 4) {
                if (j != 0 && j != 11) {
                    railTile[i][j] = true;
                }
            }

        }
    }
    safeTile[1][2] = true;
    safeTile[3][2] = true;
    safeTile[1][4] = true;
    safeTile[3][4] = true;
    safeTile[2][3] = true;
    safeTile[1][7] = true;
    safeTile[3][7] = true;
    safeTile[1][9] = true;
    safeTile[3][9] = true;
    safeTile[2][8] = true;
}

void gameboard::randPlacement() {
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
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {

            if (i == 1 || i == 3) {
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

}

bool gameboard::movePiece(int pos1x, int pos1y, int pos2x, int pos2y) {
    //case can't move there
    if (grid[pos1x][pos1y].canTake(grid[pos2x][pos2y]) == -1) {
        return false;
    }
    //case can move there
    if (grid[pos1x][pos1y].canTake(grid[pos2x][pos2y]) == 1) {
        //case isGongBing
        if(grid[pos1x][pos1y].getRank() == 0) {
            if (pos1x == pos2x) {
                goto verticalrail;
            }
            if (pos1y == pos2y) {
                goto horizontalrail;
            }
            if (pos1x != pos2x && pos1y != pos2y && railTile[pos1x][pos1y] && railTile[pos2x][pos2y]) {

            }
        }
        //case horizontal
        if ((pos1y == pos2y) && (abs(pos1x - pos2x) == 1)) {
                grid[pos2x][pos2y] = grid[pos1x][pos1y];
                grid[pos1x][pos1y] = piece();
                return true;
        }
        //horizontal railroad
        horizontalrail:
        if (pos1y == pos2y && (abs(pos1x - pos2x) > 1) && railTile[pos1x][pos1y]) {
            //right to left
            if (pos1x - pos2x > 0) {
                for (int i = pos2x + 1; i < pos1x; i++) {
                    if (grid[i][pos1y].getSide() != 0 || !railTile[i][pos1y]) {
                        return false;
                    }
                }
                grid[pos2x][pos2y] = grid[pos1x][pos1y];
                grid[pos1x][pos1y] = piece();
                return true;
            }
            //left to right
            if (pos1x - pos2x < 0) {
                for (int i = pos1x + 1; i < pos2x; i++) {
                    if (grid[i][pos1y].getSide() != 0 || !railTile[i][pos1y]) {
                        return false;
                    }
                }
                grid[pos2x][pos2y] = grid[pos1x][pos1y];
                grid[pos1x][pos1y] = piece();
                return true;
            }
        }
        //vertical railroad
        verticalrail:
        if (pos1x == pos2x) {
            if (pos1x == 0 || pos1x == 4) {
                //down
                if (pos2y - pos1y > 0) {
                    for (int i = pos2y + 1; i < pos1y; i++) {
                       if (grid[pos1x][i].getSide() != 0) {
                            return false;
                        }
                    }
                    grid[pos2x][pos2y] = grid[pos1x][pos1y];
                    grid[pos1x][pos1y] = piece();
                    return true;
                }
                //up to down
                if (pos2y - pos1y < 0) {
                    for (int i = pos1y + 1; i < pos2y; i++) {
                       if (grid[pos1x][i].getSide() != 0) {
                            return false;
                        }
                    }
                    grid[pos2x][pos2y] = grid[pos1x][pos1y];
                    grid[pos1x][pos1y] = piece();
                    return true;
                }
            }
        }
        //case vertical
        if ((pos1x == pos2x) && (abs(pos1y - pos2y) == 1)) {
                if (pos1x == 1 || pos1x == 3) {
                    if (pos1y == 1 && pos2y == 0) {
                        return false;
                    }
                    if (pos1y == 0 && pos2y == 1) {
                        return false;
                    }
                    if (pos1y == 5 && pos2y == 6) {
                      return false;
                   }
                    if (pos1y == 6 && pos2y == 5) {
                        return false;
                    }
                    if (pos1y == 10 && pos2y == 11) {
                        return false;
                    }
                    if (pos1y == 10 && pos2y == 11) {
                        return false;
                    }
                }
                grid[pos2x][pos2y] = grid[pos1x][pos1y];
                grid[pos1x][pos1y] = piece();
                return true;
        }
        //case diagonal
        if ((abs(pos1y - pos2y) == 1) && (abs(pos1x - pos2x) == 1)) {
            //from nonsafe to safe
            if (safeTile[pos2x][pos2y] && grid[pos2x][pos2y].getSide() == 0) {
                grid[pos2x][pos2y] = grid[pos1x][pos1y];
                grid[pos1x][pos1y] = piece();
                return true;
            }
            //from safe to non-safe
            if (safeTile[pos1x][pos1y]) {
                grid[pos2x][pos2y] = grid[pos1x][pos1y];
                grid[pos1x][pos1y] = piece();
                return true;
            }
        }
    }
    //case mutual annihilation
    if (grid[pos1x][pos1y].canTake(grid[pos2x][pos2y]) == 0) {
        //case horizontal
        if ((pos1y == pos2y) && (abs(pos1x - pos2x) == 1)) {
                grid[pos2x][pos2y] = piece();
                grid[pos1x][pos1y] = piece();
                return true;
        }
        //case vertical
        if ((pos1x == pos2x) && (abs(pos1y - pos2y) == 1)) {
            if (pos1x == 1 || pos1x == 3) {
                if (pos1y == 1 && pos2y == 0) {
                    return false;
                }
                if (pos1y == 0 && pos2y == 1) {
                    return false;
                }
                if (pos1y == 5 && pos2y == 6) {
                  return false;
               }
                if (pos1y == 6 && pos2y == 5) {
                    return false;
                }
                if (pos1y == 10 && pos2y == 11) {
                    return false;
                }
                if (pos1y == 10 && pos2y == 11) {
                    return false;
                }
            }
                grid[pos1x][pos1y] = piece();
                grid[pos1x][pos1y] = piece();
                return true;
        }
        //case diagonal
        if ((abs(pos1y - pos2y) == 1) && (abs(pos1x - pos2x) == 1)) {
            //from nonsafe to safe, cant take opponent piece inside safe
            if (safeTile[pos2x][pos2y]) {
                return false;
            }
            //from safe to non-safe
            if (safeTile[pos1x][pos1y]) {
                grid[pos2x][pos2y] = piece();
                grid[pos1x][pos1y] = piece();
                return true;
            }
        }
    }
    return false;
}

bool gameboard::redCanTakeBlueFlag() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (grid[i][j].getRank() == 11 && grid[i][j].getSide() == 1) {
                return false;
            }
        }
    }
    return true;
}

bool gameboard::blueCanTakeRedFlag() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (grid[i][j].getRank() == 11 && grid[i][j].getSide() == -1) {
                return false;
            }
        }
    }
    return true;
}

bool gameboard::moveFlip(int posx, int posy) {
    if (!grid[posx][posy].isRevealed()) {
        grid[posx][posy].turnPiece();
        return true;
    }
    return false;
}

piece gameboard::getPiece(int posx, int posy) {
    return grid[posx][posy];
}

bool gameboard::redVictory() {
    //if blue flag still exists
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (grid[i][j].getRank() == 10 && grid[i][j].getSide() == 1) {
                return false;
            }
        }
    }
    //if blue pieces other than mine and flag exist
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (grid[i][j].getRank() != 11 && grid[i][j].getRank() != 10) {
                if (grid[i][j].getSide() == 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool gameboard::blueVictory() {
    //if red flag still exists
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (grid[i][j].getRank() == 10 && grid[i][j].getSide() == -1) {
                return false;
            }
        }
    }
    //if red pieces other than mine and flag exist
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 12; j++) {
            if (grid[i][j].getRank() != 11 && grid[i][j].getRank() != 10) {
                if (grid[i][j].getSide() == -1) {
                    return false;
                }
            }
        }
    }
    return true;
}
