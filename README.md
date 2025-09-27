# 🌞 Solar Panels Sun Tracker

An Arduino + ESP32 project that automatically tracks the sun using Light Dependent Resistors (LDRs) and servo motors to maximize solar energy capture.  
This project was developed as part of my robotics/electronics coursework.

---

## 📖 Project Overview
Solar panels produce the most energy when directly facing the sun.  
This tracker uses **4 LDR sensors** to detect sunlight intensity and automatically adjusts the solar panel position with **2 servo motors** (horizontal & vertical movement).

Later, the system was expanded with:
- **ESP32 microcontroller** for Wi-Fi connectivity.
- **Voltage & Current sensors** for power monitoring.
- **DHT22 sensor** for temperature & humidity readings.
- **Blynk IoT app integration** to remotely monitor values and control motors manually.

---

## ⚡ Features
- Dual-axis sun tracking (horizontal & vertical).
- Real-time solar data (voltage, current, temperature, humidity).
- Mobile app dashboard via **Blynk IoT**.
- Manual override of servo motors from smartphone.
- Arduino Uno version (basic) and ESP32 version (IoT-enabled).

---

## 🛠 Hardware Used
- Arduino Uno & ESP32 boards
- 4 × LDR sensors
- 2 × Servo motors
- DHT22 temperature & humidity sensor
- Voltage sensor (on pin D25, ESP32)
- Current sensor (ACS712 on pin D26, ESP32)
- Solar panel

---

## 💻 Software Used
- Arduino IDE
- ESP32 libraries
- Blynk IoT platform
- GitHub for version control

---

## 📂 Project Structure
Arduino_Project/
│
├── arduinoblynk/ # Arduino Uno version
│ └── arduinoblynk.ino
│
├── esp32blynk/ # ESP32 IoT-enabled version
│ └── esp32blynk.ino
│
├── esp32.jpg # for esp32 GPIOs
├── .gitignore
└── README.md



---

## 🚀 Getting Started

### Clone the repository
```bash
git clone https://github.com/Hadi170/Solar-Panels-Sun-Tracker.git

```
Upload to Arduino/ESP32
Open .ino file in Arduino IDE.

Install required libraries:

-Servo.h
-BlynkSimpleEsp32.h
-DHT.h

Select correct board (Arduino Uno or ESP32).

Upload and run.
