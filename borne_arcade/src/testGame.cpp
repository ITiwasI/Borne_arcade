#include "testGame.h"

//────────────────────────────── Game parameters

#define GRID_HEIGHT 8
#define GRID_WIDTH  8

//────────────────────────────── Constructor/Destructor

testGame::testGame() : _buttonSet(false) {}

testGame::~testGame() {}

//────────────────────────────── Virtual functions override

void testGame::init() {
  // Allows the game to be run
  _quit = false;

  _gridX = 0;
  _gridY = 0;
  _lastButtonState = 0;
  // 0 is nothing, 1 is right, 2 is up, -1 is left and -2 is down
}

void testGame::initButton(button *leftB, button *rightB){
  leftButton = *leftB;
  rightButton = *rightB;
  _buttonSet = true;
}

short mm(short value, short min, short max) {
  // Same as constrain, but shorter to call
  if(value < min) return min;
  if(value > max) return max;
  return value;
}

void testGame::selectorUpdate() {
  // Avoids function call errors
  if (!_buttonSet) return;

  bool u = upButton.isPressed();
  bool d = downButton.isPressed();
  bool l = leftButton.isPressed();
  bool r = rightButton.isPressed();
  bool c = centerButton.isPressed();

  if (!u && !d && !l && !r && !c) {
    // Relaxed position
    _lastButtonState = 0;
  } else if (_lastButtonState == 0) {
    // Reminder : 0 is nothing, 1 is right, 2 is up, -1 is left and -2 is down
    if(u)      {_gridY = mm(++_gridY, 0, GRID_HEIGHT-1);   _lastButtonState =  2;}
    else if(d) {_gridY = mm(--_gridY, 0, GRID_HEIGHT-1);   _lastButtonState = -2;}
    else if(l) {_gridX = mm(--_gridX, 0, GRID_WIDTH-1);    _lastButtonState = -1;}
    else if(r) {_gridX = mm(++_gridX, 0, GRID_WIDTH-1);    _lastButtonState =  1;}
  }
}

void testGame::run() {
  while (!_quit) {
    selectorUpdate();

  }
  Serial.println("quit");
}