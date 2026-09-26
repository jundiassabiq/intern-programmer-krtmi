#ifndef SENSORJARAK_H
#define SENSORJARAK_H

#include <Arduino.h>
#include "timer.h"

#define TRIG_DEPAN 35
#define ECHO_DEPAN 36
#define TRIG_BELAKANG 37
#define ECHO_BELAKANG 38

int jarakDepan = -1;
int jarakBelakang = -1;
bool bacaDepan = true;

Timer timerJarak(70);

int ukurJarak(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long waktuEcho = pulseIn(echo, HIGH, 25000);

  if (waktuEcho == 0) {
    return -1;
  }

  return waktuEcho / 58;
}

void updateJarak() {
  if (timerJarak.Now()) {
    if (bacaDepan) {
      jarakDepan = ukurJarak(TRIG_DEPAN, ECHO_DEPAN);
      bacaDepan = false;
    } else {
      jarakBelakang = ukurJarak(TRIG_BELAKANG, ECHO_BELAKANG);
      bacaDepan = true;
    }
  }
}

void setupSensorJarak() {
  pinMode(TRIG_DEPAN, OUTPUT);
  pinMode(ECHO_DEPAN, INPUT);
  pinMode(TRIG_BELAKANG, OUTPUT);
  pinMode(ECHO_BELAKANG, INPUT);
}

#endif
