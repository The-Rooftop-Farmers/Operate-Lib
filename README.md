# Operate

**Easy stepper motor control class for Arduino with homing and position limits.**

## Overview

`Operate` is a lightweight Arduino library designed for easy and flexible control of stepper motors. It provides a simple class interface for basic stepper operations, including:

- Setting step and direction pins
- Setting motor speed (via microsecond delay)
- Moving the motor a specific number of steps in either direction
- Homing with a limit switch
- Enforcing position limits

This library is ideal for DIY CNC, pick-and-place, robotics, or any project that needs robust, basic stepper motor movement control.

---

## Features

- **Simple API** for stepper motor movement
- **Homing function** using a limit switch
- **Position limiting** to prevent out-of-range movement
- **Speed adjustment** using microsecond delay
- **No hardware timer usage** – works on any Arduino digital pins

---

## Getting Started

### Installation

1. Download or clone this repository.
2. Place the `Operate` folder into your `Arduino/libraries` directory.
3. Restart the Arduino IDE.
4. Alternatively, use **Sketch > Include Library > Add .ZIP Library...** in the Arduino IDE with the provided ZIP file.

---

### Usage Example

Move a stepper motor forward for 2 seconds, then backward for 2 seconds:

```cpp
#include <operate.h>

#define STEP_PIN 2
#define DIR_PIN 5

operate motor;

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  motor.setPin(STEP_PIN, DIR_PIN);
  motor.setSpeed(300); // microseconds between steps
}

void loop() {
  // Move forward for 2 seconds
  unsigned long startTime = millis();
  while (millis() - startTime < 2000) {
    motor.move(1, 1);
  }

  delay(500);

  // Move backward for 2 seconds
  startTime = millis();
  while (millis() - startTime < 2000) {
    motor.move(1, 0);
  }

  delay(2000);
}
```

You can find more usage examples in the `examples/` folder.

---

## API Reference

### Class: `operate`

#### Methods

- `void setPin(int stepPin, int dirPin);`  
  Set the step and direction pins.

- `void setSpeed(int microseconds);`  
  Set the delay between steps (lower is faster).

- `void move(int steps, int dir);`  
  Move the motor by `steps` steps. `dir`: 1 = forward, 0 = backward.

- `int home();`  
  Home the motor using the configured limit switch.

- `int getCurrentPos();`  
  Get the current step position.

- `int setHoming(int enabled, int speed, int timeout, int switchPin);`  
  Configure homing.

- `int setPosition(long pos);`  
  Move to a specific position, respecting limits.

- `int setPositionLimits(long max, long min);`  
  Set upper and lower bounds for movement.

---

## License

This library is released under the MIT License.

---

## Author

Malhar Ashtaputre  
GitHub: [Malhar-MA](https://github.com/Malhar-MA)  
E-mail: ashtaputremalhar@gmail.com