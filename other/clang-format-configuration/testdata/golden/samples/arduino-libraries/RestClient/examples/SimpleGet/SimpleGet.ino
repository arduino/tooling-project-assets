/*
  Simple GET client for RestClient library
  Connects to server once every five seconds, sends a GET request

  note: WiFi SSID and password are stored in config.h file.
  If it is not present, add a new tab, call it "config.h" 
  and add the following variables:
  char ssid[] = "ssid";     //  your network SSID (name)
  char pass[] = "password"; // your network password

  created 14 Feb 2016
  by Tom Igoe
  
  this example is in the public domain
 */
#include <RestClient.h>
#include <WiFi101.h>
#include "config.h"

char serverAddress[] = "192.168.0.3";  // server address
int port = 8080;

WiFiClient wifi;
RestClient client = RestClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;
String response;
int statusCode = 0;

void setup() {
  Serial.begin(9600);
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);  // print the network name (SSID);

    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
  }

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  statusCode = client.get("/");
}

void loop() {
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.println("making GET request");

  statusCode = client.get("/");
  response = client.readResponse();
  Serial.print("Response: ");
  Serial.println(response);
  Serial.println("Wait five seconds");
  delay(5000);
}
