/*
  This example creates a client object that connects and transfers
  data using always SSL.

  It is compatible with the methods normally related to plain
  connections, like client.connect(host, port).

  Written by Arturo Guadalupi
  last revision November 2015

*/

#include <SPI.h>
#include <WiFi101.h>
#include <ArduinoBearSSL.h>

char ssid[] = "yourNetwork";     //  your network SSID (name)
char pass[] = "secretPassword";  // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "google.com";  // name address for Google (using DNS)

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;
BearSSLClient sslClient(client);

unsigned long getTime() {
  return WiFi.getTime();
}

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true)
      ;
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to wifi");
  printWiFiStatus();

  ArduinoBearSSL.onGetTime(getTime);

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (sslClient.connect(server, 443)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    sslClient.println("GET /search?q=arduino HTTP/1.1");
    sslClient.println("Host: www.google.com");
    sslClient.println("Connection: close");
    sslClient.println();
  }
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (sslClient.available()) {
    char c = sslClient.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client:
  if (!sslClient.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    sslClient.stop();

    // do nothing forevermore:
    while (true)
      ;
  }
}


void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
