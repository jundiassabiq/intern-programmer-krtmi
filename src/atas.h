#ifndef ATAS_H
#define ATAS_H

#include <Arduino.h>
#include <Servo.h>

#define PWM_POMPA 9
#define IN1_POMPA 30
#define IN2_POMPA 31
#define PIN_NOZZLE_X 32
#define PIN_NOZZLE_Y 33

Servo nozzleX;
Servo nozzleY;

void pompaOn() {
  digitalWrite(IN1_POMPA, HIGH);
  digitalWrite(IN2_POMPA, LOW);
  analogWrite(PWM_POMPA, 200);
}

void pompaOff() {
  analogWrite(PWM_POMPA, 0);
  digitalWrite(IN1_POMPA, LOW);
  digitalWrite(IN2_POMPA, LOW);
}

void semprot() {
  pompaOn();

  for (int y = 80; y <= 100; y += 10) {
    nozzleY.write(y);

    for (int x = 75; x <= 105; x += 5) {
      nozzleX.write(x);
      delay(80);
    }

    for (int x = 105; x >= 75; x -= 5) {
      nozzleX.write(x);
      delay(80);
    }
  }

  pompaOff();
  nozzleX.write(90);
  nozzleY.write(90);
}

void setupAtas() {
  pinMode(PWM_POMPA, OUTPUT);
  pinMode(IN1_POMPA, OUTPUT);
  pinMode(IN2_POMPA, OUTPUT);

  nozzleX.attach(PIN_NOZZLE_X);
  nozzleY.attach(PIN_NOZZLE_Y);

  pompaOff();
  nozzleX.write(90);
  nozzleY.write(90);
}

#endif
