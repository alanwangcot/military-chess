#ifndef SAFEFILE_H
#define SAFEFILE_H

#include "tile.h"

class safetile : public tile
{
private:
    int connectedPos[8];
public:
    safetile();
    bool setPiece(piece *_p);
};

#endif // SAFEFILE_H
