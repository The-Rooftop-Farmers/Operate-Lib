#include <Arduino.h>
#include <operate.h>

// Define pin numbers for the example
#define STEP_PIN 2
#define DIR_PIN 5

operate motor;

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Set up the operate motor driver
  motor.setPin(STEP_PIN, DIR_PIN);
  motor.setSpeed(300); // Set a default speed/delay in microseconds

  // Nothing else needed in setup
}

void loop() {
  // Move forward for 2 seconds
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    motor.move(1, 1); // Move 1 step forward
    // No extra delay here, speed is controlled by setSpeed
  }

  delay(500); // Wait for half a second before changing direction

  // Move backward for 2 seconds
  startTime = millis();
  while (millis() - startTime < 2000) {
    motor.move(1, 0); // Move 1 step backward
  }

  delay(2000); // Wait for 2 seconds before repeating
}