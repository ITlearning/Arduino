const int pinPIRM = 2;

int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPIRM, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(pinPIRM);

  Serial.println(val);

  delay(100);
}
