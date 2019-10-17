int led = 11;
int g = 0;
unsigned long l1,l2;
unsigned long interval = 40;
int fDir = 0, fade = 0;
void setup() {
  // put your setup code here, to run once:
  l1 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  l2 = millis();
  if(l2 - l1 >= interval) {
    l1 = l2;
    if(!fDir) {
      fade += 5;
      if(fade > 255) {
        fade = 255; fDir = 1; }
    }else {
      fade -= 5;
      if(fade < 0) {
        fade = 0; fDir = 0;
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
    analogWrite(led, fade);
    
  }
}
