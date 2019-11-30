//50cm 이내에 사람이 5분이상 감지 되지 않으면 부재중으로 전환.
// 일단 Serial으로 값 출력

const int pinTrig = 2;
const int pinEcho = 4;
int rangeMax = 200;
int rangeMin = 0;
long T, L;
unsigned long sTime, nTime;
bool isIn;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  sTime = millis();
  isIn = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  T = pulseIn(pinEcho, HIGH);

  L = T / 58.82;

  if(L >0 && L <= 50 ){
    sTime = millis();
    isIn = true;
    delay(1000);
    nTime = millis();
  } else{
    nTime = millis();
  }

  if(nTime - sTime >= 300000) {
    isIn = false; 
  }

  if(isIn == false)
    Serial.println("patient is not in.");
  else if(isIn == true)
    Serial.println("patient is in.");
  
}
