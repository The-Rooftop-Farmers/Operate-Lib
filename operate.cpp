#include "operate.h"

operate::operate()
  : count(0), pinDir(0), pin(0), lsw(0), limitSWPin(0), currpos(0), timer(0),
    timeouttimer(0), MotSpeed(0), MotDelay(0), homingAllowed(E_NOK), MotSpeedforHoming(0),
    setPos(0), MinLimit(0), MaxLimit(0)
{
}

void operate::setPin(int p, int pD)
{
  pin = p;
  pinDir = pD;
}

void operate::setSpeed(int MotS)
{
  MotDelay = MotS;
}

void operate::move(int m, int dir)
{
  if (dir == 1) {
    digitalWrite(pinDir, LOW);
    for (count = 0; count < m; count++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(MotDelay);
      digitalWrite(pin, LOW);
      delayMicroseconds(MotDelay);
      currpos++;
    }
  } else {
    digitalWrite(pinDir, HIGH);
    for (count = 0; count < m; count++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(MotDelay);
      digitalWrite(pin, LOW);
      delayMicroseconds(MotDelay);
      currpos--;
    }
  }
}

int operate::home()
{
  digitalWrite(pinDir, HIGH);
  lsw = digitalRead(limitSWPin);
  while (lsw == HIGH && homingAllowed == E_OK) {
    lsw = digitalRead(limitSWPin);
    digitalWrite(pin, HIGH);
    delayMicroseconds(MotSpeedforHoming);
    digitalWrite(pin, LOW);
    delayMicroseconds(MotSpeedforHoming);
  }
  currpos = 0;
  return E_OK;
}

int operate::getCurrentPos()
{
  return currpos;
}

int operate::setHoming(int homing, int motspeed, int timeout, int lswPin)
{
  MotSpeedforHoming = motspeed;
  timeouttimer = timeout;
  limitSWPin = lswPin;
  if (homing == E_OK) {
    homingAllowed = E_OK;
    return E_OK;
  } else {
    homingAllowed = E_NOK;
    return E_NOK;
  }
}

int operate::setPosition(long set)
{
  long diff;
  if (set > currpos && set >= MinLimit && set <= MaxLimit) {
    diff = set - currpos;
    digitalWrite(pinDir, LOW);
    for (count = 0; count < diff; count++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(MotDelay);
      digitalWrite(pin, LOW);
      delayMicroseconds(MotDelay);
      currpos++;
    }
    return E_OK;
  } else if (set < currpos && set >= MinLimit && set <= MaxLimit) {
    diff = currpos - set;
    digitalWrite(pinDir, HIGH);
    for (count = 0; count < diff; count++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(MotDelay);
      digitalWrite(pin, LOW);
      delayMicroseconds(MotDelay);
      currpos--;
    }
    return E_OK;
  } else if (set == currpos && set >= MinLimit && set <= MaxLimit) {
    return E_OK;
  } else {
    return E_NOK;
  }
}

int operate::setPositionLimits(long max, long min)
{
  MinLimit = min;
  MaxLimit = max;
  return E_OK;
}