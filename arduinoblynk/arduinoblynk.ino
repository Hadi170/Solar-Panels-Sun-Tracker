// === ARDUINO UNO CODE ===
#include <Servo.h>
#include <SoftwareSerial.h>

// Servo pins
const int horizontalServoPin = A5;
const int verticalServoPin = A3;

// LDR analog pins
const int topLDRPin = A0;
const int bottomLDRPin = A1;
const int rightLDRPin = A2;
const int leftLDRPin = A4;

// Servo objects
Servo horizontalServo;
Servo verticalServo;

// Servo positions
int horizontalPos = 90;
int verticalPos = 45;

// Movement control
int threshold = 20;
const int stepSize = 1;
const int delayTime = 50;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2); // RX, TX

void setup() {
    mySerial.begin(9600);     // For ESP32 communication on pins 2 and 3
  Serial.begin(9600);
  horizontalServo.attach(horizontalServoPin);
  verticalServo.attach(verticalServoPin);

  horizontalServo.write(horizontalPos);
  verticalServo.write(verticalPos);
}
bool manualMode = false;

void loop() {
//manual moving::
  if (mySerial.available()) {
    Serial.println("MESSAGE RECEIVED:::::::::::");
    delay(1000);
    String command = mySerial.readStringUntil('\n');
    command.trim();
    Serial.println("Command:");
    Serial.println(command);

    if (command == "M1") {
      manualMode = true;
      Serial.println("Manual Mode ON");
      delay(500);
    } else if (command == "M0") {
      manualMode = false;
      Serial.println("Manual Mode OFF");
      delay(500);
    } else if (manualMode) {
      char cmd = command.charAt(0);
      int val = command.substring(1).toInt();

      if (cmd == 'H') {
        horizontalServo.write(val);
      } else if (cmd == 'V') {
        verticalServo.write(val);
      }
    }
  }


if(!manualMode){
  // Read LDR values
  int topLDR = analogRead(topLDRPin);
  int bottomLDR = analogRead(bottomLDRPin);
  int rightLDR = analogRead(rightLDRPin);
  int leftLDR = analogRead(leftLDRPin);

  // Print LDR values
  Serial.print("Top: "); Serial.print(topLDR);
  Serial.print(" | Bottom: "); Serial.print(bottomLDR);
  Serial.print(" | Left: "); Serial.print(leftLDR);
  Serial.print(" | Right: "); Serial.println(rightLDR);
    if(((topLDR>=900)||(bottomLDR>=900))&&(rightLDRPin>=900)||(leftLDR>=900)){
    threshold=10;
  }  if(((topLDR>=1000)||(bottomLDR>=1000))&&(rightLDRPin>=1000)||(leftLDR>=1000)){
    threshold=5;
  }else{
    threshold=20;
  }
  // Calculate vertical and horizontal differences
  int verticalDiff = topLDR - bottomLDR;
  int horizontalDiff = leftLDR - rightLDR;

  // Adjust vertical servo
  if (abs(verticalDiff) > threshold) {
    if (verticalDiff > 0 && verticalPos > 0) {
      verticalPos -= stepSize;
    } else if (verticalDiff < 0 && verticalPos < 90) {
      verticalPos += stepSize;
    }
    verticalServo.write(verticalPos);
  }

  // Adjust horizontal servo
  if (abs(horizontalDiff) > threshold) {
    if (horizontalDiff > 0 && horizontalPos > 0) {
      horizontalPos -= stepSize;
    } else if (horizontalDiff < 0 && horizontalPos < 180) {
      horizontalPos += stepSize;
    }
    horizontalServo.write(horizontalPos);
  }

  delay(delayTime);
}
}
