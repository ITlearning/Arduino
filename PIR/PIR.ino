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
}
