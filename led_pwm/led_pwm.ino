const int led = 13;
const int led_pwm = 11;
unsigned long l1,l2;
unsigned long interval = 1000;
unsigned long l3, l4;
unsigned long interval2 = 30;
int fDir = 0;
int fade = 0;
int fON = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  l1 = 0;
  l3 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();

  if(l2 - l1 >= interval) {
    l1 = l2;

    if(!fON){
      fON = HIGH;
    }else {
      fON = LOW;
    }
    digitalWrite(led, fON);
    Serial.println(fON);
    Serial.print("밝기 : ");
    Serial.println(fade);
    
  }
  
  l4 = millis();
  if(l4 - l3 >= interval2) {
    l3 = l4;
   if(!fDir){
      fade += 5;
       if(fade >= 255) {
          fade = 255; fDir = 1; }
   }else {
      fade -= 5;
      if(fade <= 0) {
        fade = 0; fDir = 0; }
    }
    analogWrite(led_pwm, fade);
   }
  }
