//including lib's
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>

//http server on port 80
ESP8266WebServer server (80);

//declaring pins for light
int led1=2;
int led2=0;

//WiFi_credentials (Read-only)
const char* ssid="ssid";
const char* password="password";

//root page
void handleRoot() {
  Serial.println("Root_Page");
  server.send(200, "text/html");
  }

//led1_on page
void handleLED1on() {
  Serial.println("LED1_ON_PAGE");
  digitalWrite(led1, 1);
  server.send(200, "text/html", "LED1_is_ON");
}

//led2_on page
void handleLED2on() {
  Serial.println("LED2_ON_PAGE");
  digitalWrite(led2, 1);
  server.send(200, "text/html", "LED2_is_ON");
}

//led1_off page
void handleLED1off() {
  Serial.println("LED1_OFF_PAGE");
  digitalWrite(led1, 0);
  server.send(200, "text/html", "LED1_is_OFF");
}

//led2_off page
void handleLED2off() {
  Serial.println("LED2_OFF_PAGE");
  digitalWrite(led2, 0);
  server.send(200, "text/html", "LED2_is_OFF");
}

//begin wifi and server
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  digitalWrite(led1, 0);
  digitalWrite(led2, 0);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
    }
  delay(1000);
  Serial.println("");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/led1_on", handleLED1on);
  server.on("/led1_off", handleLED1off);  
  server.on("/led2_on", handleLED2on);
  server.on("/led2_off", handleLED2off);

  server.begin();
  Serial.println("Server_Started");
  
  
}

//handle_client
void loop() {
  server.handleClient();
  // put your main code here, to run repeatedly:

}
