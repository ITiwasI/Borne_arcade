#include "application.h"

#ifndef Arduino_h
#include <Arduino.h>
#endif

application::application(){
}
  
application::~application() {
}  

void application::init(void) {
  //game_four_in_a_raw.init();
  //game_puissance4.init();
  game_chess.init();
}

void application::run(void) {

  //game_four_in_a_raw.run();
  //game_puissance4.run();
  game_chess.run();

}
