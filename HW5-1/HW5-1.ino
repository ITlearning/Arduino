const int pinVibM = 3;
byte count = 0;
int LED[3] = {13, 12, 11};

void setup() {
  // put your setup code here, to run once:
  pinMode(pinVibM,INPUT);
  for(int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
  }
  Serial.begin(9600);
  attachInterrupt(1, countVib, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(count != 0) {
    count = 0;
    digitalWrite(LED[0], HIGH);
    digitalWrite(LED[1], HIGH);
    digitalWrite(LED[2], HIGH);
    delay(100);
  }else {
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
    delay(100);
  }
}

void countVib() {
  count++;
}
