#include <Arduino.h>
#include <operate.h>

// Define pin numbers for the example
#define STEP_PIN 2
#define DIR_PIN 5
#define LIMIT_SWITCH_PIN 9

operate motor;

void setup() {
  Serial.begin(9600);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP);

  motor.setPin(STEP_PIN, DIR_PIN);

  // Optional: set position limits if needed
  // motor.setPositionLimits(1000, 0);

  Serial.println("Starting Stepper Motor Speed Example");
}

void loop() {
  // Move forward with increasing speed (decreasing delay)
  Serial.println("Moving forward with increasing speed...");
  for (int delayMicros = 800; delayMicros >= 100; delayMicros -= 100) {
    motor.setSpeed(delayMicros);
    motor.move(50, 1); // Move 50 steps forward at this speed
    delay(200);
  }
  delay(1000);

  // Move backward with decreasing speed (increasing delay)
  Serial.println("Moving backward with decreasing speed...");
  for (int delayMicros = 100; delayMicros <= 800; delayMicros += 100) {
    motor.setSpeed(delayMicros);
    motor.move(50, 0); // Move 50 steps backward at this speed
    delay(200);
  }
  delay(2000);
}