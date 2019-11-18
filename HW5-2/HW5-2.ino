const int pinTrig = 2;
const int pinEcho = 4;
int rangeMax = 200;
int rangeMin = 0;
long T, L;
int LEDR = 13;
int LEDG = 12;
int LEDB = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(LEDR , OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinTrig,LOW); delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  T = pulseIn(pinEcho, HIGH);

  L = T/58.82;
  
  if(L > 0 && L <= 10){
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, LOW);
    }
    else if(L > 10 && L <= 15) {
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, LOW);
    }
    else if (L > 15 && L <= 30) {
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, HIGH);
    }
    else {
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, LOW);
  }
  Serial.println(L);
  delay(100);
}
