#include "king.h"
#include "piece.h"

king pie(true, 3, 3);

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (int nx = 1; nx < 9; nx++) {
    uint8_t posX = pie.getPos()/10;
    for (int ny = 8; ny >=1; ny--) {
      if(posX == nx && (pie.getPos()%10)==ny) Serial.print("■");
      else if(pie.canMoveTo(nx,ny)) Serial.print("⮽");
      else Serial.print("☐");
    }
    Serial.println();
  }
  Serial.println();
  Serial.println();
  delay(1000);
}
