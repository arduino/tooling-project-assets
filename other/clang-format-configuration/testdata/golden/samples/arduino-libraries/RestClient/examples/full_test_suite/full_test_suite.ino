/* RestClient full test suite

   Every REST method is called.

   by Chris Continanza (csquared)
   modified by Massimo Banzi (mbanzi) to support more network devices
   modified by Tom Igoe to match new API
*/

#include <RestClient.h>
#include <WiFi101.h>
#include "config.h"

int test_delay = 1000;  //so we don't spam the API
bool describe_tests = true;

char serverAddress[] = "192.168.0.3";  // server address
int port = 8080;

WiFiClient wifi;
RestClient client = RestClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;
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
}


void test_status(int statusCode) {
  delay(test_delay);
  if (statusCode == 200) {
    Serial.print("TEST RESULT: ok (");
    Serial.print(statusCode);
    Serial.println(")");
  } else {
    Serial.print("TEST RESULT: failure (");
    Serial.print(statusCode);
    Serial.println(")");
  }
}

void test_response(String response) {
  //Serial.println(response);
  if (response == "OK") {
    Serial.println("TEST RESULT: ok (response body)");
  } else {
    Serial.println("TEST RESULT: fail (response body = " + response + ")");
  }
}

void describe(String description) {
  if (describe_tests) Serial.println(description);
}

//reusable test variables
String post_body = "POSTDATA";

void GET_tests() {
  describe("Test GET with path");
  test_status(client.get("/get"));

  describe("Test GET with path and response");
  test_status(client.get("/get"));
  test_response(client.readResponse());

  describe("Test GET with path and query");
  test_status(client.get("/get?name=Bob&age=13"));


  describe("Test GET with path and header");
  client.setHeader("X-Test-Header: true");
  test_status(client.get("/get-header"));

  describe("Test GET with path and header and response");
  client.setHeader("X-Test-Header: true");
  test_status(client.get("/get-header"));
  test_response(client.readResponse());

  describe("Test GET with 2 headers and response");
  client.setHeader("X-Test-Header1: one");
  client.setHeader("X-Test-Header2: two");
  test_status(client.get("/get-headers"));
  test_response(client.readResponse());
}

void POST_tests() {
  // POST TESTS
  describe("Test POST with path and body");
  test_status(client.post("/data", post_body));

  describe("Test POST with path and body and response");
  test_status(client.post("/data", post_body));
  test_response(client.readResponse());

  describe("Test POST with path and body and header");
  client.setHeader("X-Test-Header: true");
  test_status(client.post("/data-header", post_body));

  describe("Test POST with path and body and header and response");
  client.setHeader("X-Test-Header: true");
  test_status(client.post("/data-header", post_body));
  test_response(client.readResponse());

  describe("Test POST with 2 headers and response");
  client.setHeader("X-Test-Header1: one");
  client.setHeader("X-Test-Header2: two");
  test_status(client.post("/data-headers", post_body));
  test_response(client.readResponse());
}

void PUT_tests() {
  describe("Test PUT with path and body");
  test_status(client.put("/data", post_body));

  describe("Test PUT with path and body and response");
  test_status(client.put("/data", post_body));
  test_response(client.readResponse());

  describe("Test PUT with path and body and header");
  client.setHeader("X-Test-Header: true");
  test_status(client.put("/data-header", post_body));

  describe("Test PUT with path and body and header and response");
  client.setHeader("X-Test-Header: true");
  test_status(client.put("/data-header", post_body));
  test_response(client.readResponse());

  describe("Test PUT with 2 headers and response");
  client.setHeader("X-Test-Header1: one");
  client.setHeader("X-Test-Header2: two");
  test_status(client.put("/data-headers", post_body));
  test_response(client.readResponse());
}

void DELETE_tests() {
  describe("Test DELETE with path");
  //note: requires a special endpoint
  test_status(client.del("/del"));

  describe("Test DELETE with path and body");
  test_status(client.del("/data", post_body));

  describe("Test DELETE with path and body and response");
  test_status(client.del("/data", post_body));
  test_response(client.readResponse());

  describe("Test DELETE with path and body and header");
  client.setHeader("X-Test-Header: true");
  test_status(client.del("/data-header", post_body));

  describe("Test DELETE with path and body and header and response");
  client.setHeader("X-Test-Header: true");
  test_status(client.del("/data-header", post_body));
  test_response(client.readResponse());

  describe("Test DELETE with 2 headers and response");
  client.setHeader("X-Test-Header1: one");
  client.setHeader("X-Test-Header2: two");
  test_status(client.del("/data-headers", post_body));
  test_response(client.readResponse());
}


// Run the tests!
void loop() {
  GET_tests();
  POST_tests();
  PUT_tests();
  DELETE_tests();
  while (true)
    ;
}
