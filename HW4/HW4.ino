const int pinLM35 = 1;
int pinLED[3] = { 11, 10 , 9};
int val = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int i = 0; i < 3; i++) {
      pinMode(pinLED[i], OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pinLM35);
  
  int tmp = val * 5 * 100 / 1024.0;
  
  if(tmp > 30){
    digitalWrite(pinLED[2], HIGH);
    digitalWrite(pinLED[0], LOW);
    delay(500);
  }else {
     digitalWrite(pinLED[2], LOW);
     digitalWrite(pinLED[0], HIGH);
     delay(500);
  }

  
}
