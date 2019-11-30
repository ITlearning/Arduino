<<<<<<< HEAD
const int SEN_PIR=3;  
const int ACT_LED=12;
int PIRval=0;  

void setup(){  
  pinMode(SEN_PIR,INPUT);  
  pinMode(ACT_LED,OUTPUT);
  Serial.begin(9600);
}  
void loop(){  
  PIRval=digitalRead(SEN_PIR);  
  Serial.println(PIRval);  
  if(PIRval==1)
    digitalWrite(ACT_LED,HIGH);
    else
    digitalWrite(ACT_LED,LOW); 
=======
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
>>>>>>> ff8a0b1ccb1565898957232ec0101ab10492da85
}
