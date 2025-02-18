#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* scriptURL = "YOUR_GAS_WEB_APP_URL";  //ここにウェブアプリURLを入力してください

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(scriptURL);
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{\"sensor1\": 23.5, \"sensor2\": 45.2, \"sensor3\": 78.9}";
    
    int httpResponseCode = http.POST(jsonPayload);
    Serial.println("Response: " + String(httpResponseCode));

    http.end();
  }
  delay(5000); 
}