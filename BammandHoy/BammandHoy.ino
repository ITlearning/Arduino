unsigned long l1,l2,l3,l4;
unsigned long interval1 = 1000;
unsigned long interval2 = 3000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  l1 = 0;
  l3 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();
  if( l2 - l1 >= interval1 ) {
    l1 = l2;
    Serial.println("BAMM!!");
  }

  l4 = millis();
  if (l4 - l3 >= interval2) {
    l3 = l4;
    Serial.println("HOY!!");
  }
}
