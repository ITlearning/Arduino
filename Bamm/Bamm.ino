unsigned long l1, l2;
unsigned long interval = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  l1 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();

  if(l2 - l1 >= interval) {
    l1 = l2;
    
    Serial.println("BAMMMM!!!!!");
  }
}
