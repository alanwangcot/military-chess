#ifndef TILE_H
#define TILE_H

#include "piece.h"
#include <QWidget>

class tile : public QObject{
        Q_OBJECT
private:
    bool highway;
    bool safe;
    piece *p;
    int vertPos,horPos;
public:
    tile() {
        highway = false;
        safe = false;
        p = nullptr;
        vertPos = horPos = 0;
    }
    tile(int vert, int hor) {
        vertPos = vert;
        horPos = hor;
        p = nullptr;
        highway = false;
        safe = false;
        if (vertPos == 1 || vertPos == 5 || vertPos == 6 || vertPos == 10) {
            highway = true;
        }
        if (horPos == 0 || horPos == 4) {
            if (vertPos != 0 && vertPos != 11) {
                highway = true;
            }
        }
        if (vertPos == 2 || vertPos == 4 || vertPos == 7 || vertPos == 9) {
            if (horPos == 1 || horPos == 3) {
                safe = true;
            }
        }
        if (vertPos == 3 || vertPos == 8) {
            if (horPos == 2) {
                safe = true;
            }
        }
    }
    bool onHighway() {
        return highway;
    }
    bool isSafe() {
        return safe;
    }


public slots:
    void setPiece(piece np) {
        p = &np;
    }
    piece* getPiece() {
        return p;
    }


};


#endif // TILE_H
