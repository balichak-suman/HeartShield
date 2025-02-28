# Emergency Heart Attack Detector

## Overview

The **Emergency Heart Attack Detector** is a **wearable IoT device** that continuously monitors the user's **pulse rate** and detects sudden drops that indicate a potential heart attack. When a critical drop is detected, the device automatically **sends an emergency alert** with the user's real-time location to **family members and nearby hospitals** via SMS.

## Features

- **Real-time Heart Rate Monitoring** using a **BMX Sensor**.
- **Automatic Emergency Alert** when abnormal heart rate is detected.
- **GPS Tracking** to share real-time location.
- **GSM-based Communication** using a **SIM900 module**.
- **Buzzer Alert** to notify the user.
- **Battery-Powered Wearable Device**.

---

## Components Used

| Component                             | Description                                 |
| ------------------------------------- | ------------------------------------------- |
| **Arduino Nano**                      | Microcontroller to process sensor data      |
| **BMX Sensor (MAX30100 or MAX30102)** | Pulse rate monitoring sensor                |
| **SIM900 GSM Module**                 | Sends SMS alerts in case of emergency       |
| **NEO-6M GPS Module**                 | Captures real-time location                 |
| **Buzzer**                            | Alerts the user during a critical situation |
| **Lithium Battery (3.7V)**            | Powers the wearable device                  |

---

## Circuit Diagram

**Circuit Connections:**

| **Component**                      | **Arduino Nano**                                        | **Other Connections** |
| ---------------------------------- | ------------------------------------------------------- | --------------------- |
| **BMX Sensor (Heart Rate Sensor)** | VCC → **5V**, GND → **GND**, SDA → **A4**, SCL → **A5** | I2C Communication     |
| **SIM900 GSM Module**              | VCC → **5V**, GND → **GND**, TX → **D10**, RX → **D9**  | Serial Communication  |
| **NEO-6M GPS Module**              | VCC → **3.3V**, GND → **GND**, TX → **D2**, RX → **D3** | UART Communication    |
| **Buzzer**                         | Positive → **D6**, Negative → **GND**                   | Alarm System          |
| **Lithium Battery**                | Positive → **VIN**, Negative → **GND**                  | Power Source          |



---

## Installation & Setup

### 1️⃣ **Clone the Repository**

```sh
 git clone https://github.com/your-username/emergency-heart-attack-detector.git
 cd emergency-heart-attack-detector
```

### 2️⃣ **Upload the Code to Arduino Nano**

- Open `Arduino IDE`.
- Install necessary libraries (`Wire.h`, `SoftwareSerial.h`, `TinyGPS.h` for GPS support).
- Connect Arduino Nano via USB and upload the code.

### 3️⃣ **Power the Device**

- Connect the **3.7V lithium battery** to the power input.
- The device will start monitoring **heart rate and location**.

---

## Working Principle

1. **Heart Rate Monitoring**:
   - The **BMX Sensor** continuously measures the **pulse rate**.
2. **Abnormal Detection**:
   - If the heart rate drops below a **critical threshold**, an alert is triggered.
3. **Emergency Alert**:
   - The **SIM900 GSM module** sends an **SOS SMS** containing the **real-time GPS location** to predefined numbers (family/hospital).
4. **Buzzer Alert**:
   - The buzzer **beeps loudly** to alert nearby people.

---

## Future Improvements

- **Integration with a Mobile App** for real-time monitoring.
- **Cloud Storage** for storing patient health data.
- **Smartwatch Integration** for better wearability.

---

## License

This project is **open-source** and licensed under the **MIT License**. Feel free to use, modify, and distribute it.

---

## Author

👨‍💻 **Balichak Suman**\
📧 **Contact:** [suman@example.com](mailto\:suman@example.com)\
🔗 **GitHub:** [github.com/your-username](https://github.com/your-username)

