#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "yFwLw9_YN6AYq9Yj5kCb90BzCb9Qw_sc";

char ssid[] = "Sandeep Bansal_2.4ghz";
char pass[] = "gggggggg";
BLYNK_WRITE(V3){
  int r = param[0].asInt();
  int g = param[1].asInt();
  int b = param[2].asInt();
  analogWrite(5, r);
  analogWrite(4, g);
  analogWrite(0, b);
}
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
