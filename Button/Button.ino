const int pinLEDR = 9;
const int pinLEDG = 10;
const int pinLEDB = 11;
const int pinButton = 2;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean stateLED = false;
int ledMode = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDG, OUTPUT);
  pinMode(pinLEDB, OUTPUT);
  pinMode(pinButton, INPUT);
}
boolean debounce(boolean last) {
  boolean current = digitalRead(pinButton);
  if(current != last) {
    delay(5);
    current = digitalRead(pinButton);
  }
  return current;
}
void loop() {
  currentButton = debounce(lastButton);
  if(currentButton == HIGH && lastButton == LOW){
     ledMode++; if(ledMode > 3) ledMode = 0;
  }
  lastButton = currentButton;
  setMode(ledMode);
}

void setMode(int mode) {
  switch(mode) {
    case 0: digitalWrite(pinLEDR, LOW);
            digitalWrite(pinLEDG, LOW);
            digitalWrite(pinLEDB, LOW);
            break;
    case 1: digitalWrite(pinLEDR, 102);
            digitalWrite(pinLEDG, 000);
            digitalWrite(pinLEDB, 102);
            break;
    case 2: digitalWrite(pinLEDR, 000);
            digitalWrite(pinLEDG, 102);
            digitalWrite(pinLEDB, 102);
            break;
    case 3: digitalWrite(pinLEDR, 255);
            digitalWrite(pinLEDG, 102);
            digitalWrite(pinLEDB, 153);
            break;
  }
}
