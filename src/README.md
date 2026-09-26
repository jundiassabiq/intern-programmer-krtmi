# Robot Pemadam — Versi Belajar

Program dibuat sederhana untuk internship:

1. Robot berhenti dan scan pada lima posisi servo.
2. Jika menemukan api, robot berputar ke kiri, kanan, atau belakang.
3. Robot maju sambil membaca flame dan memperbarui ultrasonik.
4. Robot berhenti jika ada benda dalam 15 cm.
5. Jika nilai flame mencapai 750, pompa menyala dan nozzle menyapu.

Semua urutan misi terlihat langsung di `firefighting-robot.ino`.

## Variabel yang berubah

Program utama hanya bergantung pada hasil berikut:

- `apiDepan` dan `apiBelakang`
- `nilaiApi` dan `arahApi`
- `jarakDepan` dan `jarakBelakang`

Nama pin dan pilihan arah memakai `#define`. Angka kecepatan, sudut, ambang,
dan waktu ditulis langsung di tempat pemakaian agar mudah ditemukan intern.

## Pin Arduino Mega 2560

| Perangkat | Pin |
| --- | --- |
| FR | PWM 5, arah 22/23 |
| FL | PWM 6, arah 24/25 |
| BL | PWM 7, arah 26/27 |
| BR | PWM 8, arah 28/29 |
| Pompa | PWM 9, arah 30/31 |
| Nozzle X/Y | 32/33 |
| Servo scan | 34 |
| HC-SR04 depan | TRIG 35, ECHO 36 |
| HC-SR04 belakang | TRIG 37, ECHO 38 |
| Flame depan/belakang | A0/A1 |

## Angka yang harus dikalibrasi

- `400`: batas api mulai dianggap terdeteksi.
- `750`: batas api dianggap cukup dekat untuk disemprot.
- `900`: waktu putar 90 derajat.
- `1800`: waktu putar 180 derajat.
- `90`: PWM maju.
- `100`: PWM putar.
- `15`: batas benda dekat dalam cm.
- Sudut nozzle 75–105 dan 80–100.

## Catatan ultrasonik

`updateJarak()` dijadwalkan oleh `Timer` setiap 70 ms dan membaca sensor depan
dan belakang secara bergantian. Antarmuka ini tidak memakai `delay()` milidetik.

Namun, `pulseIn(..., 25000)` masih dapat menunggu echo maksimal 25 ms. Ini
sengaja dipilih agar kodenya mudah dipelajari. Saat aktuator menjalankan
`delay()`, pembaruan ultrasonik juga ikut tertunda.

Nilai jarak `-1` berarti echo tidak terbaca. Lakukan uji komponen satu per satu
sebelum menjalankan misi lengkap. Pastikan ground semua catu tersambung dan servo
memakai suplai yang sesuai.
