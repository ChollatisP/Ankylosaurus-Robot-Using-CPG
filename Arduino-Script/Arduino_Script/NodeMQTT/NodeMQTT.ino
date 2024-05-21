#include <WiFi.h>
#include "PubSubClient.h"
#include <ESP32Servo.h>
#define GPIO_PIN_1 2 
#define GPIO_PIN_2 15

const char* ssid = "GGOOGG";
const char* password = "0123456789";
const char* mqttServer = "broker.emqx.io";
int port = 1883;
String stMac;
char mac[50];
char clientId[50];

WiFiClient espClient;
PubSubClient client(espClient);
Servo ServoMouth;
Servo ServoNeck;
int randNgum=3;

void setup() {
  Serial.begin(115200);
  Serial.println(ssid);
  pinMode(GPIO_PIN_1, OUTPUT); // กำหนด GPIO เป็นโหมด OUTPUT
  pinMode(GPIO_PIN_2, OUTPUT);
  ServoMouth.attach(16);
  ServoNeck.attach(17);
  ServoMouth.write(0);
  ServoNeck.write(40);
  wifiConnect();
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  /*Serial.println(WiFi.macAddress());
  stMac = WiFi.macAddress();
  stMac.replace(":", "_");
  Serial.println(stMac);*/
  client.setServer(mqttServer, port);
  client.setCallback(callback);
}

void wifiConnect() {
  //WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void mqttReconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    long r = random(1000);
    sprintf(clientId, "clientId-%ld", r);
    if (client.connect(clientId)) {
      Serial.print(clientId);
      Serial.println(" connected");
      client.subscribe("ControGG");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String stMessage;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    stMessage += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "ControGG") {
    Serial.print("Changing output to ");
    Serial.print(stMessage);
    
    if(stMessage == "Forward"){
    digitalWrite(GPIO_PIN_1, HIGH);
    }
    else if(stMessage == "Stop"){
   digitalWrite(GPIO_PIN_1, LOW);
    }
    else if(stMessage == "Eat"){
      digitalWrite(GPIO_PIN_1, LOW);
      randNgum = random(2,6);
      ngum(randNgum);
     digitalWrite(GPIO_PIN_1, HIGH);
    }
  }
}

void loop() {
  delay(10);
  if (!client.connected()) {
    mqttReconnect();
  }
  client.loop();
}

void ngum(int i)
{
  delay(1000);
  for(int posDegrees = 40; posDegrees >= 0; posDegrees--) {
    ServoNeck.write(posDegrees);
    delay(10);
  }
  for(int j = 0;j<=i;j++)
  {
    for(int posDegrees = 0; posDegrees <= 45; posDegrees++) {
    ServoMouth.write(posDegrees);
    delay(7);
    }
    for(int posDegrees = 45; posDegrees >= 0; posDegrees--) {
    ServoMouth.write(posDegrees);
    delay(7);
    }
  }
  delay(300);
  for(int posDegrees = 0; posDegrees <= 40; posDegrees++) {
    ServoNeck.write(posDegrees);
    delay(10);
  }
}
