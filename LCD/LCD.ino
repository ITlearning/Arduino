#include <LiquidCrystal.h>
<<<<<<< HEAD
const int LM35 = 1;
int digi = 0;
int LED = 13;
LiquidCrystal lcd(2,3,4,5,6,7);
float set = 27.0, cur;
byte degree[8]={
        B00110,
        B01001,
        B01001,
        B00110,
        B00000,
        B00000,
        B00000,
        B00000,
};

byte fan_off[8]={
        B00100,
        B00100,
        B00100,
        B11111,
        B00100,
        B00100,
        B00100,
        B00000,
};

byte fan_on[8]={
        B00100,
        B10101,
        B01110,
        B11111,
        B01110,
        B10101,
        B00100,
        B00000,
};
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(0, degree);
  lcd.createChar(1, fan_off);
  lcd.createChar(2, fan_on);

  lcd.setCursor(0,0); lcd.print("Set:");
  lcd.setCursor(10,0); lcd.write((byte)0);
  lcd.setCursor(11,0); lcd.print("C");
  lcd.setCursor(0,1); lcd.print("Cur:");
  lcd.setCursor(10,1); lcd.write((byte)0);
  lcd.setCursor(11,1); lcd.print("C");
  pinMode(LED, OUTPUT);
=======
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
>>>>>>> ff8a0b1ccb1565898957232ec0101ab10492da85
}

void loop() {
  // put your main code here, to run repeatedly:
<<<<<<< HEAD
  digi = analogRead(LM35);

  cur = (digi *5 * 100) / 1024.0;
  
  lcd.setCursor(6,0); lcd.print(set,1);
  lcd.setCursor(6,1); lcd.print(cur,1);
  lcd.setCursor(15,1);
  if(cur > set) {
    lcd.write(2);
    digitalWrite(LED, HIGH);
  }
  else{
    lcd.write(1);
    digitalWrite(LED,LOW);
  }
  delay(500);
=======
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
>>>>>>> ff8a0b1ccb1565898957232ec0101ab10492da85
}
