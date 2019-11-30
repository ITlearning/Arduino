const int pinTilt = 2;

int val = 0;

void setup() {
  pinMode(pinTilt, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(pinTilt);


    if(val != 0) {
      Serial.println("뚜껑 열렸당");
    }else {
      Serial.println("다시 열어랑");
    }
   
    
  
  delay(100);
}
