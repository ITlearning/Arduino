#include<SoftwareSerial.h> 

SoftwareSerial mySerial(4,5); 
byte a;
byte c;

  void setup(){ 
  mySerial.begin(9600);  
  Serial.begin(9600);
  }
  
  void loop(){ 
     if(mySerial.available()){ 
      c = mySerial.read();  
      Serial.write(c); 
      }
      
      else if(Serial.available()){
     a =  Serial.read();
     mySerial.write(a);
     Serial.write(a);
    }
    }
