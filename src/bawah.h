#ifndef BAWAH_H
#define BAWAH_H

#include <Arduino.h>

#define PWM_FR 5
#define IN1_FR 22
#define IN2_FR 23

#define PWM_FL 6
#define IN1_FL 24
#define IN2_FL 25

#define PWM_BL 7
#define IN1_BL 26
#define IN2_BL 27

#define PWM_BR 8
#define IN1_BR 28
#define IN2_BR 29

void aturMotor(int pwm, int in1, int in2, int speed) {
  if (speed > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (speed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }

  analogWrite(pwm, abs(speed));
}

void FR(int speed) {
  aturMotor(PWM_FR, IN1_FR, IN2_FR, speed);
}

void FL(int speed) {
  aturMotor(PWM_FL, IN1_FL, IN2_FL, speed);
}

void BL(int speed) {
  aturMotor(PWM_BL, IN1_BL, IN2_BL, speed);
}

void BR(int speed) {
  aturMotor(PWM_BR, IN1_BR, IN2_BR, speed);
}

void maju(int speed) {
  FR(speed);
  FL(speed);
  BL(speed);
  BR(speed);
}

void mundur(int speed) {
  FR(-speed);
  FL(-speed);
  BL(-speed);
  BR(-speed);
}

void putarkanan(int speed) {
  FR(-speed);
  FL(speed);
  BL(speed);
  BR(-speed);
}

void putarkiri(int speed) {
  FR(speed);
  FL(-speed);
  BL(-speed);
  BR(speed);
}

void geserkanan(int speed) {
  FR(-speed);
  FL(speed);
  BL(-speed);
  BR(speed);
}

void geserkiri(int speed) {
  FR(speed);
  FL(-speed);
  BL(speed);
  BR(-speed);
}

void berhenti() {
  FR(0);
  FL(0);
  BL(0);
  BR(0);
}

void setupBawah() {
  pinMode(PWM_FR, OUTPUT);
  pinMode(IN1_FR, OUTPUT);
  pinMode(IN2_FR, OUTPUT);

  pinMode(PWM_FL, OUTPUT);
  pinMode(IN1_FL, OUTPUT);
  pinMode(IN2_FL, OUTPUT);

  pinMode(PWM_BL, OUTPUT);
  pinMode(IN1_BL, OUTPUT);
  pinMode(IN2_BL, OUTPUT);

  pinMode(PWM_BR, OUTPUT);
  pinMode(IN1_BR, OUTPUT);
  pinMode(IN2_BR, OUTPUT);

  berhenti();
}

#endif
