#include <WiFi.h>        // Include the Wi-Fi library
#include <WebServer.h>
#include <E

const char *ssid = "ESP32 Access Point"; // The name of the Wi-Fi network that will be created
const char *password = "your-password";   // The password required to connect to it, leave blank for an open

WebServer server(80);

// to make this function work, just send 192.168.4.1/data/?teste=25

void handleSentVar() {
  if (server.hasArg("teste")) { // this is the variable sent from the client
    int readingInt = server.arg("teste").toInt();
    Serial.print(readingInt);
    server.send(200, "text/html", "Data received");
  }
}

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println('\n');

  WiFi.softAP(ssid, password);             // Start the access point
  delay(100);
  Serial.print("Access Point \"");
  Serial.print(ssid);
  Serial.println("\" started");

  IPAddress IP(192, 168, 1, 1);           //Setting IP
  IPAddress Mask(255, 255, 255, 0);       //Setting Network Mask
  WiFi.softAPConfig(IP, IP, Mask);        //Configuring Access Point with IP as IP, Gateway as IP (can be changed), and Network Mask as Mask

  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());         // Send the IP address of the ESP32 to the computer
  
  server.on("/data/", HTTP_GET, handleSentVar); // when the server receives a request with /data/ in the string then run the handleSentVar function
  server.begin();
}

void loop() {
  server.handleClient();
}
