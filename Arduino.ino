#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial sim900(7, 8);  // SIM900 TX, RX
SoftwareSerial gpsSerial(4, 3);  // GPS TX, RX

TinyGPSPlus gps;
int bpmPin = A0;  // Pulse sensor connected to A0
int buzzer = 9;
int threshold = 50;  // Set your low BPM threshold

void setup() {
    Serial.begin(9600);
    sim900.begin(9600);
    gpsSerial.begin(9600);
    
    pinMode(buzzer, OUTPUT);
    
    Serial.println("Heart Attack Detector Initialized...");
}

void loop() {
    int bpm = analogRead(bpmPin);  // Read BPM value
    bpm = map(bpm, 0, 1023, 0, 200); // Adjust scaling

    Serial.print("BPM: ");
    Serial.println(bpm);

    if (bpm < threshold) {
        Serial.println("ALERT: Low Heartbeat Detected!");
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        sendAlert();
        delay(5000); // Avoid spamming messages
    }
    
    while (gpsSerial.available()) {
        gps.encode(gpsSerial.read());
    }

    delay(1000);
}

void sendAlert() {
    String message = "EMERGENCY: Heart Attack Detected! Location: ";
    
    if (gps.location.isValid()) {
        message += "Lat: " + String(gps.location.lat(), 6) + " Lon: " + String(gps.location.lng(), 6);
    } else {
        message += "GPS signal lost!";
    }

    sim900.println("AT+CMGF=1");
    delay(1000);
    sim900.println("AT+CMGS=\"+91XXXXXXXXXX\""); // Replace with family/hospital number
    delay(1000);
    sim900.print(message);
    delay(1000);
    sim900.write(26);  // End SMS
    Serial.println("Alert Sent!");
}
