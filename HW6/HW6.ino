int Button[8] = {6,7,8,9,10,11,12,13};
const int Buzzer = 3;
int a;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 9; i++) {
    pinMode(Button[i], INPUT);
  }
  pinMode(Buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 9; i++) {
    if(digitalRead(Button[i]) == HIGH){
     a =i;
      if(a == 0) {
        tone(Buzzer, 262); delay(150);
        Serial.println("0");
      }else if(a == 1) {
        tone(Buzzer, 294); delay(150);
        Serial.println("1");
      }else if(a == 2) {
        tone(Buzzer, 330); delay(150);
        Serial.println("2");
      }else if(a == 3) {
        tone(Buzzer, 349); delay(150);
        Serial.println("3");
      }else if(a == 4) {
        tone(Buzzer, 392); delay(150);
        Serial.println("4");
      }else if(a == 5) {
        tone(Buzzer, 440); delay(150);
        Serial.println("5");
      }else if(a == 6) {
        tone(Buzzer, 494); delay(150);
        Serial.println("6");
      }else if(a == 7) {
        tone(Buzzer, 523); delay(150);
        Serial.println("7");
      }
    }else {
        noTone(Buzzer);
    }
  }
  
}
