int pinButton[6] = {2, 3, 4, 5, 6, 7};
int pinLED[6] = {8,9,10, 11, 12, 13};
int lastButton[6] = {LOW, LOW, LOW, LOW, LOW, LOW};
int currentButton[6] = {LOW, LOW, LOW, LOW, LOW, LOW};
int stateLED[6] = {false, false, false, false, false, false};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i< 6; i++) {
    pinMode(pinLED[i], OUTPUT);
  }
  for(int i = 0; i < 6; i++) {
    pinMode(pinButton[i], INPUT);
  }
}

boolean debounce(boolean last, int pin) {
  boolean current = digitalRead(pin);
  if(current != last) {
    delay(5);
    current = digitalRead(pin);
  }
  return current;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 6; i++) {
    currentButton[i] = debounce(lastButton[i], pinButton[i]);
  }

  for(int i = 0; i < 6; i++) {
    if(currentButton[i] == HIGH && lastButton[i] == LOW) {
      stateLED[i] = !stateLED[i];     
  }
  lastButton[i] = currentButton[i];
  digitalWrite(pinLED[i], stateLED[i]);
}
}
