#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <WiFi.h>
#include <ArduinoWebsockets.h>
#include <ArduinoJson.h>

using namespace websockets;

// Replace with your Wi-Fi credentials
const char* ssid = "#######";
const char* password = "########";

// WebSocket server settings
const char* serverAddress = "########";  // Replace with your server's local IP
const int serverPort = 8080;                  // Replace with your server's port
const char* serverPath = "/";                 // WebSocket path if any

WebsocketsClient webSocket;
Adafruit_MPU6050 mpu;

// Pin Definitions
const int left1Pin = 34;  // Left hand, index finger
const int left2Pin = 35;  // Left hand, middle finger
const int left3Pin = 32;  // Left hand, ring finger
const int left4Pin = 33;  // Left hand, little finger
const int left5Pin = 25;  // Left hand, thumb

const int right1Pin = 26;  // Right hand, index finger
const int right2Pin = 27;  // Right hand, middle finger
const int right3Pin = 14;  // Right hand, ring finger
const int right4Pin = 12;  // Right hand, little finger
const int right5Pin = 13;  // Right hand, thumb

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("\nConnecting to Wi-Fi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Connect to WebSocket server
  String url = "ws://" + String(serverAddress) + ":" + String(serverPort) + serverPath;
  webSocket.connect(url);

  if (webSocket.available()) {
    Serial.println("[WebSocket] Connected");
  } else {
    Serial.println("[WebSocket] Connection failed");
  }

  // Initialize flex sensor pins
  pinMode(left1Pin, INPUT);
  pinMode(left2Pin, INPUT);
  pinMode(left3Pin, INPUT);
  pinMode(left4Pin, INPUT);
  pinMode(left5Pin, INPUT);

  pinMode(right1Pin, INPUT);
  pinMode(right2Pin, INPUT);
  pinMode(right3Pin, INPUT);
  pinMode(right4Pin, INPUT);
  pinMode(right5Pin, INPUT);

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(1000);
    }
  }

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("Setting up...");
  delay(500);
}

void loop() {
  delay(1000);

  // Keep WebSocket connection alive
  if (webSocket.available()) {
    webSocket.poll();

    // Read left-hand flex sensor values
    int left1 = analogRead(left1Pin);
    int left2 = analogRead(left2Pin);
    int left3 = analogRead(left3Pin);
    int left4 = analogRead(left4Pin);
    int left5 = analogRead(left5Pin);

    // Read right-hand flex sensor values
    int right1 = analogRead(right1Pin);
    int right2 = analogRead(right2Pin);
    int right3 = analogRead(right3Pin);
    int right4 = analogRead(right4Pin);
    int right5 = analogRead(right5Pin);

    // Get new MPU6050 sensor events
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // Create JSON object
    StaticJsonDocument<200> doc;
    doc["left1"] = left1;
    doc["left2"] = left2;
    doc["left3"] = left3;
    doc["left4"] = left4;
    doc["left5"] = left5;
    doc["right1"] = right1;
    doc["right2"] = right2;
    doc["right3"] = right3;
    doc["right4"] = right4;
    doc["right5"] = right5;
    doc["right_ax"] = a.acceleration.x;
    doc["right_ay"] = a.acceleration.y;
    doc["right_az"] = a.acceleration.z;
    doc["right_gx"] = g.gyro.x;
    doc["right_gy"] = g.gyro.y;
    doc["right_gz"] = g.gyro.z;

    // Serialize JSON object to string
    String jsonString;
    serializeJson(doc, jsonString);

    // Example of sending data periodically
    static unsigned long lastSendTime = 0;
    unsigned long currentTime = millis();

    if (currentTime - lastSendTime > 2000) {  // Send every 2 seconds
      String message = "Hello from ESP32! Time: " + String(currentTime);
      webSocket.send(jsonString);
      Serial.println("[WebSocket] Sent: " + jsonString);
      lastSendTime = currentTime;
    }
  } else {
    Serial.println("[WebSocket] Disconnected, attempting to reconnect...");
    String url = "ws://" + String(serverAddress) + ":" + String(serverPort) + serverPath;
    webSocket.connect(url);
  }
}
