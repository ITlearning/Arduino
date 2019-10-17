const int led_pwm = 11;
const int led_G = 10;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  for(int i = 0; i < 230; i +=5) {
    analogWrite(led_pwm, i);
    delay(10);
    analogWrite(led_G, i);
  }

  for(int i = 235; i > 0; i -=5) {
    analogWrite(led_pwm, i);
    delay(10);
    analogWrite(led_G, i);
  }

}
