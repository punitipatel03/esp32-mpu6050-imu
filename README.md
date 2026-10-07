# ESP32 MPU6050 IMU Sensor Reader

Reads raw accelerometer, gyroscope, and temperature data from an MPU6050 6-axis IMU over I2C on an ESP32, converts it to physical units, and streams it over Serial.

## Features
- Direct register-level I2C communication with the MPU6050 (no external library)
- 3-axis acceleration in **g** (±2g range, 16384 LSB/g)
- 3-axis angular velocity in **°/s** (±250°/s range, 131 LSB/°/s)
- On-chip temperature in **°C**
- Serial output at 115200 baud, updated every second

## Hardware
| MPU6050 | ESP32   |
|---------|---------|
| VCC     | 3.3V    |
| GND     | GND     |
| SDA     | GPIO 21 |
| SCL     | GPIO 22 |

## Usage
1. Open `imu.ino` in the Arduino IDE with ESP32 board support installed.
2. Select your ESP32 board and port, then upload.
3. Open the Serial Monitor at **115200 baud**.

## Sample Output
```
===== MPU6050 =====
Acceleration X: 0.02 g
Acceleration Y: -0.01 g
Acceleration Z: 1.00 g

Angular Velocity X: -0.35 °/s
Angular Velocity Y: 0.42 °/s
Angular Velocity Z: 0.11 °/s

Temperature: 28.47 °C
-----------------------------
```
