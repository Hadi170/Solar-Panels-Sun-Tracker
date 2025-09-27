// === ESP32 CODE ===
#include <HardwareSerial.h>
#include <DHT.h>
#include <WiFi.h>
//BLYNK:::
#define BLYNK_TEMPLATE_ID "TMPL6MdhMgjty"
#define BLYNK_TEMPLATE_NAME "Solar Tracker"
#define BLYNK_AUTH_TOKEN "l4T2x6haXZ-fuFvIQn_kg4k8gkL6o2"
#include <BlynkSimpleEsp32.h>

//WIFI CONNECTION:
char ssid[] = "hadi";
char pass[] = "hadiwifi123";

BlynkTimer timer;
// Voltage sensor:
int voltagePin = 34;
float voltage = 0.0;

// Current sensor:
const int currentPin = 32;
const float sensorOffset = 2.36;
const float sensitivity = 0.185;

// DHT22 sensor
#define DHTPIN 14  // DHT22 data pin connected to D12
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// UART2 for communication with Arduino
HardwareSerial mySerial(2);  // UART2 (TXD2: Pin 17, RXD2: Pin 16)

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600, SERIAL_8N1, 16, 17);
  dht.begin();

  // Start WiFi manually
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println(WiFi.localIP());

  // Now connect to Blynk
  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();

  timer.setInterval(5000L, sendData);
}


void loop() {
  //blynk:
  Blynk.run();
  timer.run();
  // Voltage sensor
  int raw = analogRead(voltagePin);
  float vOut = (raw / 4095.0) * 3.3;
  Serial.print("Voltage: ");
  Serial.println(vOut);

  // Current sensor
  int rawValue = analogRead(currentPin);
  float vCurrent = (rawValue / 4095.0) * 3.3;
    Serial.print("vCurrent raw voltage: ");
Serial.println(vCurrent);
delay(1000);
  float current = abs(((vCurrent - sensorOffset) / sensitivity));
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");

  // DHT22 temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (!isnan(temperature) && !isnan(humidity)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Failed to read from DHT22 sensor!");
  }

  delay(100);
}
void sendData() {
  // Voltage
  int raw = analogRead(voltagePin);
  float vOut = (raw / 4095.0) * 3.3;
  vOut*=5;
  Blynk.virtualWrite(V0, vOut);

  // Current
  int rawCurrent = analogRead(currentPin);
  float vCurrent = (rawCurrent / 4095.0) * 3.3;
  float current = abs(((vCurrent - sensorOffset) / sensitivity));
  Blynk.virtualWrite(V1, current);

  // DHT
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  if (!isnan(temp) && !isnan(hum)) {
    Blynk.virtualWrite(V2, temp);
    Blynk.virtualWrite(V3, hum);
  }
//voltage-current-temp-hum serialmonitor
  Serial.print("Sending to Blynk -> Voltage: "); Serial.println(voltage);
Serial.print("Sending to Blynk -> Current: "); Serial.println(current);
Serial.print("Sending to Blynk -> Temp: "); Serial.println(temp);
Serial.print("Sending to Blynk -> Hum: "); Serial.println(hum);
delay(500);
}

//manual configuration:
int manualHorizontal = -1;
int manualVertical = -1;
//manual mode
bool manualMode = false;

BLYNK_WRITE(V6) {
  manualMode = param.asInt(); // 1 = manual, 0 = auto
  Serial.println("MANUAL");
  delay(300);
  if (manualMode) {
    mySerial.println("M1");  // Tell Arduino manual mode ON
  } else {
    mySerial.println("M0");  // Tell Arduino manual mode OFF
  }
}
//manual horizontal
BLYNK_WRITE(V4) {
  manualHorizontal = param.asInt();
  Serial.print("Sending Horizontal: ");
  Serial.println(manualHorizontal);
  mySerial.print("H");
  mySerial.println(manualHorizontal);
}
//manual vertical
BLYNK_WRITE(V5) {
  manualVertical = param.asInt();
  Serial.print("Sending Vertical: ");
  Serial.println(manualVertical);
  mySerial.print("V");
  mySerial.println(manualVertical);
}
