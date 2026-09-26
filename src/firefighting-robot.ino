#include "bawah.h"
#include "atas.h"
#include "sensorapi.h"
#include "sensorjarak.h"

void setup() {
  Serial.begin(115200);

  setupBawah();
  setupAtas();
  setupSensorApi();
  setupSensorJarak();
}

void loop() {
  // 1. Robot diam lalu mencari api.
  berhenti();
  pompaOff();
  scanApi();

  // Nilai 400 adalah batas api terdeteksi.
  if (nilaiApi < 400) {
    return;
  }

  // 2. Jangan bergerak jika ada benda dekat.
  updateJarak();
  if (jarakDepan > 0 && jarakDepan <= 15) {
    return;
  }

  // 3. Putar badan menuju arah api.
  if (arahApi == KIRI) {
    putarkiri(100);
    delay(900);
  } else if (arahApi == KANAN) {
    putarkanan(100);
    delay(900);
  } else if (arahApi == BELAKANG) {
    putarkanan(100);
    delay(1800);
  }

  berhenti();
  servoScan.write(90);
  delay(300);

  // 4. Maju selama api masih terlihat dan belum dekat.
  bacaApi();

  while (apiDepan >= 400 && apiDepan < 750) {
    updateJarak();

    if (jarakDepan > 0 && jarakDepan <= 15) {
      break;
    }

    maju(90);
    delay(50);
    bacaApi();
  }

  berhenti();

  // 5. Semprot hanya jika api sudah dekat dan jalan tidak terhalang.
  if (apiDepan >= 750) {
    if (jarakDepan < 0 || jarakDepan > 15) {
      semprot();
    }
  }

  // Setelah selesai, loop kembali melakukan scan.
}
