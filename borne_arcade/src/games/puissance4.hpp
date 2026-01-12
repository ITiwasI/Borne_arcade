#ifndef _puissance4_hpp_
#define _puissance4_hpp_

#include "game.h"
#include "../components/button.h"
#include "puissance4/grid.hpp"

class puissance4 : public game {
  private :
    Grid grid4;
    int push;
    char CurrentPlayer;
  
  public : 
    puissance4();
    ~puissance4();

    void init(void);
    void run(void);
    void end(void);
    
    button rightButton;
    button centerButton;
    
  };

#endif // _puissance4_hpp_