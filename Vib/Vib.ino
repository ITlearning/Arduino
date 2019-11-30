const int pinVibM = 3;
byte count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinVibM,INPUT);
  Serial.begin(9600);
  attachInterrupt(1,countVib, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(count != 0) {
    count = 0;
    Serial.println(1);
    delay(100);
  }else {
    Serial.println(0);
    delay(100);
  }
}

void countVib() {
  count++;
}
