#include "application.h"
#include <Arduino.h>

application::application(){
}
  
application::~application() {
}  

void application::init(void) {
  Serial.begin(115200);

  game_four_in_a_raw.init();
  //game_puissance4.init();

}

void application::run(void) {

  game_four_in_a_raw.run();
  //game_puissance4.run();

}
