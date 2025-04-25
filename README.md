# 🚦 Pedestrian Safety System using IoT

This project is an IoT-based Pedestrian Safety System that uses IR sensors, ultrasonic sensors, and NeoPixel LEDs to detect pedestrian presence and control crosswalk lighting and smart streetlights.

## 🌟 Features
- Detects pedestrians at three crosswalk positions (entry, mid, exit)
- Detects vehicles using ultrasonic sensors
- Uses PIR motion sensors for early pedestrian detection
- NeoPixel LEDs indicate crosswalk status (Green, Orange, Red)
- Buzzer triggers emergency alert when pedestrian and vehicle are detected together
- Simulated input using potentiometers

## 🧠 System Overview
- **IR Sensors**: Detect footstep at three crosswalk points
- **Ultrasonic Sensors**: Detect vehicles and standing pedestrians
- **PIR Sensors**: Sense approaching pedestrian motion
- **NeoPixel LED**: Replaces a strip to show status using one light
- **Buzzer**: Used in emergency cases
- **Potentiometers**: Used in place of actual IR sensors for testing

## 🛠️ Components Used
| Component             | Quantity |
|----------------------|----------|
| IR Sensor (TCRT5000) | 3        |
| Ultrasonic Sensor    | 4        |
| PIR Motion Sensor    | 2        |
| NeoPixel LED         | 1        |
| Buzzer               | 1        |
| ESP32 / Arduino Uno  | 1        |
| Potentiometer        | 3        |

## 📷 Demo

![pedestrian safety system  (1)](https://github.com/user-attachments/assets/8bf2f925-16f9-40c3-8892-497b89624377)
![pedestrian safety system  (2)](https://github.com/user-attachments/assets/7b34d9e6-657e-4009-ac12-e7d5f2441ac3)

> Developed by karthick.B
