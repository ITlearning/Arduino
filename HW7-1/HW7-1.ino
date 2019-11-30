int PinLEDR = 13;
int PinLEDG = 12;
int PinLEDB = 11;
boolean countR = LOW;
boolean countG = LOW;
boolean countB = LOW;
char c;

void setup() {
  Serial.begin(9600);
  pinMode(PinLEDR, OUTPUT);
  pinMode(PinLEDG, OUTPUT);
  pinMode(PinLEDB, OUTPUT);
}


void loop() {
  if(Serial.available()) {
    c = Serial.read();

    if(c == 'r') {
      countR = !countR;
     if(countR == HIGH) {
      digitalWrite(PinLEDR, HIGH);
      digitalWrite(PinLEDG, LOW);
      digitalWrite(PinLEDB, LOW);
     }else if (countR == LOW) {
      digitalWrite(PinLEDR, LOW);
      digitalWrite(PinLEDG, LOW);
      digitalWrite(PinLEDB, LOW);
     }
    }else if(c == 'g') {
      countG = !countG;
     if(countG== HIGH) {
      digitalWrite(PinLEDR, LOW);
      digitalWrite(PinLEDG, HIGH);
      digitalWrite(PinLEDB, LOW);
     }else if (countG == LOW) {
      digitalWrite(PinLEDR, LOW);
      digitalWrite(PinLEDG, LOW);
      digitalWrite(PinLEDB, LOW);
     }
    }else if(c == 'b') {
      countB = !countB;
     if(countB == HIGH) {
      digitalWrite(PinLEDR, LOW);
      digitalWrite(PinLEDG, LOW);
      digitalWrite(PinLEDB, HIGH);
     }else if (countB == LOW) {
      digitalWrite(PinLEDR, LOW);
      digitalWrite(PinLEDG, LOW);
      digitalWrite(PinLEDB, LOW);
     }
    }
  }
}
