#include <Servo.h>
Servo Biteservo;         //servomotor 를 정의합니다.
int pos = 0;             //서보 모터의 시작 지점을 선정합니다. 

void setup() {
  Biteservo.attach(5);       //신호를 받을부분의 핀을 선정합니다. 저희는 2번핀에 준비합니다.
}

void loop() {
  for(pos = 0; pos < 180; pos+=1) //서보의 위치 0~180도 각을 정의합니다.
  {
    Biteservo.write(pos);   
    delay(1);
  }
  for(pos = 180; pos >= 1; pos-=1) // 180도에서 0도까지 내려갑니다.
  {
    Biteservo.write(pos);            
    delay(1);
  }
}
