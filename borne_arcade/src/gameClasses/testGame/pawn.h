#ifndef PAWN_H_
#define PAWN_H_

#include "Arduino.h"
#include "tile.h"

class pawn : public tile {
  public :
    pawn(bool wh);
    ~pawn();
  private :
    uint8_t _posX;
    uint8_t _posY;
};
#endif