#ifndef RAILTILE_H
#define RAILTILE_H

#include "tile.h"

class railtile : public tile
{
private:
    int connectedRails[];
public:
    railtile();
    bool setPiece(piece *_p);
};

#endif // RAILTILE_H
