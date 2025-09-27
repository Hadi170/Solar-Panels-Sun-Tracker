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
- Voltage sensor 
- Current sensor 
- Solar panel

**Note: Don't forget to follow the specific pins for each sensor inside the code, otherwise you will have to make your own changes.**


**You can use the image below to check esp32 GPIOs pins**



![Image](https://github.com/user-attachments/assets/56b849e9-7021-48a5-a9df-443f333b9f3a)


---



## 💻 Software Used
- Arduino IDE
- ESP32 and Arduino Uno libraries
- Blynk IoT platform
- GitHub for version control




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


**Demo Video:
**
[![Watch the video](https://img.shields.io/badge/Video-Demo-blue?logo=github)](https://github.com/Hadi170/Solar-Panels-Sun-Tracker/releases/download/V1.0/ROBOTICS2.mp4)



