const int led_RED = 13;
const int led_GREEN = 12;
const int led_YELLOW = 8;
unsigned long l1,l2,l3,l4;
unsigned long in_R = 1000;
unsigned long in_G = 2000;
unsigned long in_Y = 3000;
int fON_RED = 0;
int fON_GREEN = 0;
int fON_YELLOW = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_RED, OUTPUT);
  pinMode(led_GREEN, OUTPUT);
  pinMode(led_YELLOW, OUTPUT);
  l1 = 0;
  l2 = 0;
  l3 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l4 = millis();
  if(l4 - l1 >= in_R) {
    l1 = l4;

    if(!fON_RED) {
      fON_RED = HIGH;
    }else {
      fON_RED = LOW;
    }
    digitalWrite(led_RED, fON_RED);
  }

  if(l4 - l2 >= in_G) {
    l2 = l4;

    if(!fON_GREEN) {
      fON_GREEN = HIGH;
    }else {
      fON_GREEN = LOW;
    }
    digitalWrite(led_GREEN, fON_GREEN);
  }

  if(l4 - l3 >= in_Y) {
    l3 = l4;

    if(!fON_YELLOW) {
      fON_YELLOW = HIGH;
    }else {
      fON_YELLOW = LOW;
    }
    digitalWrite(led_YELLOW, fON_YELLOW);
  }
}
