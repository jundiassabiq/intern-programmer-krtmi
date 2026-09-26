#ifndef SENSORAPI_H
#define SENSORAPI_H

#include <Arduino.h>
#include <Servo.h>

#define PIN_API_DEPAN A0
#define PIN_API_BELAKANG A1
#define PIN_SERVO_SCAN 34

#define KIRI 1
#define DEPAN 2
#define KANAN 3
#define BELAKANG 4

Servo servoScan;

int apiDepan = 0;
int apiBelakang = 0;
int nilaiApi = 0;
int arahApi = DEPAN;

void bacaApi() {
  // Modul diasumsikan menghasilkan ADC lebih kecil saat api lebih kuat.
  apiDepan = 1023 - analogRead(PIN_API_DEPAN);
  apiBelakang = 1023 - analogRead(PIN_API_BELAKANG);
}

void scanApi() {
  nilaiApi = 0;
  arahApi = DEPAN;

  // Cukup lima posisi agar logikanya mudah dipelajari.
  for (int sudut = 0; sudut <= 180; sudut += 45) {
    servoScan.write(sudut);
    delay(150);
    bacaApi();

    if (apiDepan > nilaiApi) {
      nilaiApi = apiDepan;

      if (sudut < 90) {
        arahApi = KIRI;
      } else if (sudut == 90) {
        arahApi = DEPAN;
      } else {
        arahApi = KANAN;
      }
    }

    // Sensor belakang dipasang berlawanan dengan sensor depan.
    if (apiBelakang > nilaiApi) {
      nilaiApi = apiBelakang;

      if (sudut < 90) {
        arahApi = KANAN;
      } else if (sudut == 90) {
        arahApi = BELAKANG;
      } else {
        arahApi = KIRI;
      }
    }
  }

  servoScan.write(90);
  delay(300);
}

void setupSensorApi() {
  pinMode(PIN_API_DEPAN, INPUT);
  pinMode(PIN_API_BELAKANG, INPUT);

  servoScan.attach(PIN_SERVO_SCAN);
  servoScan.write(90);
}

#endif
