const int led = 13;
unsigned long l1,l2;
unsigned long interval = 1000;
int fON = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  l1 = 0;
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
    
  }

   
}
