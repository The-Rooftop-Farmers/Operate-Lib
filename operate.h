#ifndef OPERATE_H
#define OPERATE_H

#include <Arduino.h>

// Define error codes if not already defined elsewhere
#ifndef E_OK
#define E_OK 0
#endif

#ifndef E_NOK
#define E_NOK 1
#endif

class operate
{
public:
  operate();

  void setPin(int p, int pD); // Set PWM and direction pins for stepper
  void setSpeed(int MotS); // Set stepper motor speed (delay)
  void move(int m, int dir); // Move by m steps, dir: 1-F, 0-R
  int home(); // Home the motor
  int getCurrentPos(); // Get current position of motor
  int setHoming(int homing, int motspeed, int timeout, int lswPin); // Configure homing
  int setPosition(long set); // Set position of stepper motor
  int setPositionLimits(long max, long min); // Set max and min limits

private:
  long count; // Loop counter
  int pinDir; // Direction pin
  int pin; // PWM pin
  int lsw; // Limit switch state
  int limitSWPin; // Limit switch pin
  long currpos; // Current position
  int timer;
  int timeouttimer; // Timeout for homing
  int MotSpeed; // Unused but kept for compatibility
  int MotDelay; // Motor delay for PWM
  int homingAllowed; // Homing enabled/disabled
  int MotSpeedforHoming; // Motor speed for homing
  long setPos; // Set position
  long MinLimit; // Minimum position limit
  long MaxLimit; // Maximum position limit
};

#endif // OPERATE_H