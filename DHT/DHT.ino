#include <dht11.h>
const int pinDHT11 = 2;
int ret;
dht11 DHT11;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ret = DHT11.read(pinDHT11);
  switch(ret) {
  case DHTLIB_OK: Serial.println("OK"); break;
  case DHTLIB_ERROR_CHECKSUM: Serial.println("Checksum error"); break;
  case DHTLIB_ERROR_TIMEOUT: Serial.println("Time out error"); break;
  default: Serial.println("Unknown error"); break;
  }
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (oC): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);
}
