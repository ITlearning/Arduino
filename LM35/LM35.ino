econst int pinLM35 = 1;

int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pinLM35);

  Serial.println(val * 5 * 100 / 1024.0);

  delay(500);
}
