const int led_RED = 13;
const int led_GREEN = 12;
const int led_YELLOW = 8;
unsigned long l1,l2,l3,l4,l5,l6;
unsigned long in_R = 2000;
unsigned long in_G = 4000;
unsigned long in_Y = 6000;
int fON_RED = 0;
int fON_GREEN = 0;
int fON_YELLOW = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_RED, OUTPUT);
  pinMode(led_GREEN, OUTPUT);
  pinMode(led_YELLOW, OUTPUT);
  l1 = 0;
  l3 = 0;
  l5 = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();
  l4 = millis();
  l6 = millis();
  if(l2 - l1 >= in_R) {
    l1 = l2;

    if(!fON_RED) {
      fON_RED = HIGH;
    }else {
      fON_RED = LOW;
    }
    digitalWrite(led_RED, fON_RED);
  }

  if(l4 - l3 >= in_G) {
    l3 = l4;

    if(!fON_GREEN) {
      fON_GREEN = HIGH;
    }else {
      fON_GREEN = LOW;
    }
    digitalWrite(led_GREEN, fON_GREEN);
  }

  if(l6 - l5 >= in_Y) {
    l5 = l6;

    if(!fON_YELLOW) {
      fON_YELLOW = HIGH;
    }else {
      fON_YELLOW = LOW;
    }
    digitalWrite(led_YELLOW, fON_YELLOW);
  }
}
