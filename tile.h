#ifndef TILE_H
#define TILE_H

#include "piece.h"

class tile {
protected:
    piece* p;
    int pos;
    bool occupied;
public:
    tile() {

    }
    bool setPiece(piece *_p);
};

#endif // TILE_H
