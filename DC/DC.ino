const int pinRelay = 3;
byte c = 0;
char b = 'a';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinRelay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()) {
    b = Serial.read();
    Serial.println(b);

    if(b =='o') {
      digitalWrite(pinRelay, HIGH);
      Serial.println("Start turning");
    }else if (b == 'f'){
      digitalWrite(pinRelay, LOW);
      Serial.println("Stop turning");
    }
  }
}
