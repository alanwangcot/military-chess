#include "safetile.h"

safetile::safetile()
{

}

bool safetile::setPiece(piece *_p) {
    if (p->getRank() ==0) {
       p = _p;
       occupied = true;
       return true;
    }
    return false;
}
