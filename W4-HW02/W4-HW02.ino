int led = 11;
int g = 0;
unsigned long l1,l2;
unsigned long interval = 40;
int fDir_R = 0, fade_R = 0;
void setup() {
  // put your setup code here, to run once:
  l1 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();
  if(l2 - l1 >= interval) {
    l1 = l2;
    if(!fDir_R) {
      fade_R += 5;
      if(fade_R > 255) {
        fade_R = 255; fDir_R = 1; }
    }else {
      fade_R -= 5;
      if(fade_R < 0) {
        fade_R = 0; fDir_R = 0;
        if(led == 11) {
          led--;
          g = 0;
        }else if(led == 10) {
              if(g == 0){
                led--;
              }else if(g == 1) {
                led++;
              }
          } else if(led == 9){
            led++;
            g = 1;
          }
        }
    }
    analogWrite(led, fade_R);
    
  }
}
