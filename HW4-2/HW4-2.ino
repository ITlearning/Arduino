<<<<<<< HEAD
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
=======
const int pinTilt = 3;
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
  val = analogRead(pinTilt);
  
  if(val == 0){
    digitalWrite(pinLED[2], LOW);
    digitalWrite(pinLED[1], LOW);
    digitalWrite(pinLED[0], LOW);
  delay(100);
  }else {
    digitalWrite(pinLED[2], HIGH);
    digitalWrite(pinLED[1], HIGH);
    digitalWrite(pinLED[0], HIGH);
  delay(100);
  }

  
}
>>>>>>> ff8a0b1ccb1565898957232ec0101ab10492da85
