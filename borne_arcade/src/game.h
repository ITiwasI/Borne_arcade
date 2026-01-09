#ifndef GAME_H_
#define GAME_H_

#include "button.h"

class game
{
  public :
    game();
    ~game();    
    
    virtual void init(button * leftButton, button * rightButton)=0;
    virtual void run(void);
    
  protected :
    bool _quit;
};
#endif