#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>
 
const char* ssid = "Leekhandchildren";            // your ssid
const char* password = "leekh1004";       // your password of ssid
 
#define mqtt_server "m15.cloudmqtt.com"    // your MQTT server
#define mqtt_port 13114                    // your port number
#define mqtt_topic "test"         // your topic
#define mqtt_user "pwimfegh"               // your username (Manage User of the CloudMQTT)
#define mqtt_password "-0W9VFJqoYxL"             // your password (Manage User of the CloudMQTT)
 
int pinLED = 2;                            // internal LED (1 for ESP-1, 2 for ESP-12F)
int pinSwitch = 12;                         // switch pin (2 for ESP-1, 5 for ESP-12F)
int pinState = HIGH;
 
Servo myServo;
Servo myServo1;
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
 
  pinMode(pinLED, OUTPUT);
  pinMode(pinSwitch, INPUT_PULLUP);
 
  myServo.attach(4);                                // pin of Servo Motor (D1 or GPIO5)
 
  myServo1.attach(5);
  
  pinState = digitalRead(pinSwitch);
  digitalWrite(pinLED, pinState);
 
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}
 
void loop() {
  if (!client.connected()) {
    client.connect("ESP8266Client", mqtt_user, mqtt_password);
    client.subscribe(mqtt_topic); 
  }
  if (pinState != digitalRead(pinSwitch)) {
    pinState = !pinState;
    client.publish(mqtt_topic, pinState? "Switch A OFF" : "Switch A ON");
  }
  client.loop();
}
 
void callback(char* topic, byte* payload, unsigned int length) {
  String Msg = "";
  int i=0;
  while (i<length) Msg += (char)payload[i++];
  if (Msg == "Push A") {
    digitalWrite(pinLED, !digitalRead(pinLED));
    client.publish(mqtt_topic, (digitalRead(pinLED) ? "Switch A OFF" : "Switch A ON"));
    return;
  }
  if (Msg == "Switch A OFF") {
    
      digitalWrite(pinLED, LOW);
      myServo.attach(4);
      myServo.write(100);
      delay(200);
      myServo.detach();
    
  }
  if (Msg == "Switch A ON"){
   
      digitalWrite(pinLED, HIGH);
      myServo.attach(4);
      myServo.write(20);
      delay(200);
      myServo.detach();
    
  }
} 
