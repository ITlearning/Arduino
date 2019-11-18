#include <dht11.h>
const int pinDHT11 = 2;
float hum;
float temp;
dht11 DHT11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Temp,Humi,Time,Counter");
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT11.read(pinDHT11);
  hum = DHT11.humidity;
  temp = DHT11.temperature;
  Serial.print("DATA, ");
  Serial.print(temp);
  Serial.print(", ");
  Serial.print(hum);
  Serial.print(", ");
  Serial.println("TIME,");
  delay(1800000);
}
