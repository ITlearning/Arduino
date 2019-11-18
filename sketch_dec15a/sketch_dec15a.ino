int TouchSensor = 5;
  
void setup() {

  Serial.begin(9600);

  pinMode(TouchSensor, INPUT);

}




void loop() {

  int a = digitalRead(TouchSensor);

  Serial.println(a);

  delay(1);

}
