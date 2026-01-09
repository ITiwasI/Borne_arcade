#ifndef _gamePuissance4_hpp_
#define _gamePuissance4_hpp_

#include "button.h"

class gamePuissance4 : public game {
  pulic : 
    gamePuissance4();
    ~gamePuissance4();

    void init(&leftButton, &rightButton, &upButton, &downButton, &centerButton);
    void run(void);
    
  private :
    button leftButton;
    button rightButton;
    button upButton;
    button downButton;
    button centerButton;
    bool _buttonSet;
    short _lastButtonState;
    
  };

#endif