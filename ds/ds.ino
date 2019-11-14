#include <LiquidCrystal.h>
const int RS = 2; const int EN = 3;
const int D4 = 4; const int D5 = 5;
const int D6 = 6; const int D7 = 7;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Hello, Arduino!");
  lcd.setCursor(0,1);
  lcd.print("Embedded Systems");
  delay(1000); lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j = 0; j < 2; j++) {
      for(int i = 0; i < 16; i++) {
        lcd.setCursor(i,j);
        lcd.print("X"); delay(100);
      }
    }

    for(int j = 1; j >= 0; j--) {
      for(int i = 15; i >= 0; i--) {
        lcd.setCursor(i,j);
        lcd.print("O"); delay(100);
      }
    }
}
