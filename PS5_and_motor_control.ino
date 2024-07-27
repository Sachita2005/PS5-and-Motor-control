#include <ps5Controller.h>

const int fPin1 = 4;       // Digital pin 1 for forward motor
const int fPin2 = 5;       // Digital pin 2 for forward motor
const int fEnablePin = 13; // PWM pin for forward motor speed control
const int sPin1 = 12;      // Digital pin 1 for second motor
const int sPin2 = 14;      // Digital pin 2 for second motor
const int sEnablePin = 15; // PWM pin for second motor speed control

void setup() {
  Serial.begin(921600);
  pinMode(fPin1, OUTPUT);
  pinMode(fPin2, OUTPUT);
  pinMode(fEnablePin, OUTPUT);
  pinMode(sPin1, OUTPUT);
  pinMode(sPin2, OUTPUT);
  pinMode(sEnablePin, OUTPUT);
  ps5.begin("E8:47:3A:0F:65:EE"); // Replace with MAC address of your controller
  Serial.println("Ready.");
}

void loop() {
  if (ps5.isConnected()) {
    Serial.println("Connected!");
  } else {
    Serial.println("Not connected!");
  }
  
  delay(3000);

  while (ps5.isConnected()) {
    checkControllerInputs();
    delay(300); // To make the output more human-readable, remove if not needed
  }
}

void checkControllerInputs() {
  if (ps5.Right()) Serial.println("Right- direction Button");
  if (ps5.Down()) Serial.println("Down- direction Button");
  if (ps5.Up()) Serial.println("Up- direction Button");
  if (ps5.Left()) Serial.println("Left- direction Button");
  if (ps5.Square()) Serial.println("Square Button");
  if (ps5.Cross()) Serial.println("Cross Button");
  if (ps5.Circle()) Serial.println("Circle Button");
  if (ps5.Triangle()) Serial.println("Triangle Button");
  if (ps5.UpRight()) Serial.println("Up Right");
  if (ps5.DownRight()) Serial.println("Down Right");
  if (ps5.UpLeft()) Serial.println("Up Left");
  if (ps5.DownLeft()) Serial.println("Down Left");
  if (ps5.L1()) Serial.println("L1 Button");
  if (ps5.R1()) Serial.println("R1 Button");
  if (ps5.Share()) Serial.println("Share Button");
  if (ps5.Options()) Serial.println("Options Button");
  if (ps5.L3()) Serial.println("L3 Button");
  if (ps5.R3()) Serial.println("R3 Button");
  if (ps5.PSButton()) Serial.println("PS Button");
  if (ps5.Touchpad()) Serial.println("Touch Pad Button");
  if (ps5.L2()) Serial.printf("L2 button at %d\n", ps5.L2Value());
  if (ps5.R2()) Serial.printf("R2 button at %d\n", ps5.R2Value());
  if (ps5.LStickX()) Serial.printf("Left Stick-L3 x at %d\n", ps5.LStickX());
  if (ps5.LStickY()) Serial.printf("Left Stick-L3 y at %d\n", ps5.LStickY());
  if (ps5.RStickX()) Serial.printf("Right Stick x-R3 at %d\n", ps5.RStickX());
  if (ps5.RStickY()) Serial.printf("Right Stick y-R3 at %d\n", ps5.RStickY());

  handleMotorControl();
}

void handleMotorControl() {
  if (ps5.LStickY() > 100) {
    forward();
  } else if (ps5.LStickY() < 20) {
    backward();
  } else if (ps5.RStickY() > 100) {
    rotateleft();
  } else if (ps5.RStickY() < 20) {
    rotateright();
  } else {
    stop();
  }
}

void forward() {
  analogWrite(fEnablePin, 128);  // Example PWM value (0-255) for half-speed
  analogWrite(sEnablePin, 128); 
  digitalWrite(fPin1, LOW);
  digitalWrite(fPin2, HIGH);
  digitalWrite(sPin1, LOW);
  digitalWrite(sPin2, HIGH);
}

void backward() {
  analogWrite(fEnablePin, 128);  // Example PWM value (0-255) for half-speed
  analogWrite(sEnablePin, 128); 
  digitalWrite(fPin1, HIGH);
  digitalWrite(fPin2, LOW);
  digitalWrite(sPin1, HIGH);
  digitalWrite(sPin2, LOW);
}

void stop() {
  analogWrite(fEnablePin, 0);  // Example PWM value (0-255) for half-speed
  analogWrite(sEnablePin, 0);
}

void rotateright() {
  analogWrite(fEnablePin, 128);  // Example PWM value (0-255) for half-speed
  analogWrite(sEnablePin, 128); 
  digitalWrite(fPin1, HIGH);
  digitalWrite(fPin2, LOW);
  digitalWrite(sPin1, LOW);
  digitalWrite(sPin2, HIGH);
}

void rotateleft() {
  analogWrite(fEnablePin, 128);  // Example PWM value (0-255) for half-speed
  analogWrite(sEnablePin, 128); 
  digitalWrite(fPin1, LOW);
  digitalWrite(fPin2, HIGH);
  digitalWrite(sPin1, HIGH);
  digitalWrite(sPin2, LOW);
}

void right() {
  analogWrite(fEnablePin, 128);  // Example PWM value (0-255) for half-speed
  analogWrite(sEnablePin, 128); 
  digitalWrite(fPin1, HIGH);
  digitalWrite(fPin2, LOW);
  digitalWrite(sPin1, LOW);
  digitalWrite(sPin2, HIGH);
}

void left() {
  analogWrite(fEnablePin, 128);  // Example PWM value (0-255) for half-speed
  analogWrite(sEnablePin, 128); 
  digitalWrite(fPin1, LOW);
  digitalWrite(fPin2, HIGH);
  digitalWrite(sPin1, HIGH);
  digitalWrite(sPin2, LOW);
}
