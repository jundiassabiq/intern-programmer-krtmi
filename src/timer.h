#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {
  private:
    unsigned long waktuTerakhir = 0;
    unsigned long jeda;

  public:
    Timer(unsigned long jedaMs) {
      jeda = jedaMs;
    }

    bool Now() {
      unsigned long sekarang = millis();

      if (sekarang - waktuTerakhir >= jeda) {
        waktuTerakhir = sekarang;
        return true;
      }

      return false;
    }
};

#endif
