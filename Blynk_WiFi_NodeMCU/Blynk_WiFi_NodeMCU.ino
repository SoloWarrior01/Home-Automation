#define BLYNK_PRINT Serial

#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


Servo servo;
char auth[] = "sQKiobb7-cy_kbbWmJU0P7madQiHfcH-";

char ssid[] = "Sandeep Bansal_2.4ghz";
char pass[] = "gggggggg";
BLYNK_WRITE(V1){
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();
  analogWrite(5, r);
  analogWrite(4, g);
  analogWrite(0, b);
}

BLYNK_WRITE(V2){
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();
  analogWrite(14, r);
  analogWrite(12, g);
  analogWrite(13, b);
}

BLYNK_WRITE(V4){
  int val = param.asInt();
  digitalWrite(2, val);
  digitalWrite(0, 255-val);
  digitalWrite(4, 255-val);
  digitalWrite(5, 255-val);
  digitalWrite(15, val);
  digitalWrite(12, 255-val);
  digitalWrite(13, 255-val);
  digitalWrite(14, 255-val);
  
}
BLYNK_WRITE(V6){
  int val = param.asInt();
  if(val==0){
    servo.write(360);
  }
  else{
    servo.write(90);
  }
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  servo.attach(16);
  servo.write(0);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
