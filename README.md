# Operate

Easy stepper motor control class for Arduino with homing and position limits.

## Overview

Operate is a lightweight Arduino library designed for easy and flexible control of stepper motors. It provides a simple class interface for basic stepper operations, including:

- Setting step and direction pins
- Setting motor speed (via microsecond delay)
- Moving the motor a specific number of steps in either direction
- Homing with a limit switch
- Enforcing position limits

This library is ideal for DIY CNC, pick-and-place, robotics, or any project that needs robust, basic stepper motor movement control.

---

## Features

- Simple API for stepper motor movement
- Homing function using a limit switch
- Position limiting to prevent out-of-range movement
- Speed adjustment using microsecond delay
- No hardware timer usage – works on any Arduino digital pins

---

## Installation

1. Download or clone this repository.
2. Place the `Operate` folder into your `Arduino/libraries` directory.
3. Restart the Arduino IDE.
4. Alternatively, use **Sketch > Include Library > Add .ZIP Library...** in the Arduino IDE with the provided ZIP file.

---

## Examples

You can find example usage sketches in the [`examples/`](https://github.com/The-Rooftop-Farmers/Operate-Lib/tree/main/examples) directory. These include:

- Basic stepper operation
- Speed control
- Homing
- Using position limits

---

## Documentation

For detailed usage and the full API reference, please see the [Wiki](https://github.com/The-Rooftop-Farmers/Operate-Lib/wiki).

---

## License

This library is released under the MIT License.

---

## Author

Malhar Ashtaputre  
GitHub: [Malhar-MA](https://github.com/Malhar-MA)  
E-mail: ashtaputremalhar@gmail.com
