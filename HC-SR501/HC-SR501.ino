const int pinTrig = 2;
const int pinEcho = 4;
int rangeMax = 200;
int rangeMin = 0;
long T,L;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinTrig, LOW); delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  T = pulseIn(pinEcho, HIGH);

  L = T/58.82;

  if(L >= rangeMax || L <= rangeMin) Serial.println("ERROR");
  else {Serial.print(L); Serial.println(" cm");}
  delay(100);
}
