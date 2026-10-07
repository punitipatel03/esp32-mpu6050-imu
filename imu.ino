#include <Wire.h>

#define MPU6050_ADDR 0x68

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  // Wake up MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();

  Serial.println("MPU6050 started");
  Serial.println("-----------------------------");
}

void loop() {

  int16_t AccX, AccY, AccZ;
  int16_t TempRaw;
  int16_t GyroX, GyroY, GyroZ;

  // Start reading from register 0x3B
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU6050_ADDR, 14, true);

  // Accelerometer
  AccX = Wire.read() << 8 | Wire.read();
  AccY = Wire.read() << 8 | Wire.read();
  AccZ = Wire.read() << 8 | Wire.read();

  // Temperature
  TempRaw = Wire.read() << 8 | Wire.read();

  // Gyroscope
  GyroX = Wire.read() << 8 | Wire.read();
  GyroY = Wire.read() << 8 | Wire.read();
  GyroZ = Wire.read() << 8 | Wire.read();

  // Convert acceleration to g
  float ax = AccX / 16384.0;
  float ay = AccY / 16384.0;
  float az = AccZ / 16384.0;

  // Convert gyroscope to degrees per second
  float gx = GyroX / 131.0;
  float gy = GyroY / 131.0;
  float gz = GyroZ / 131.0;

  // Convert temperature
  float temperature = (TempRaw / 340.0) + 36.53;

  Serial.println("===== MPU6050 =====");

  Serial.print("Acceleration X: ");
  Serial.print(ax);
  Serial.println(" g");

  Serial.print("Acceleration Y: ");
  Serial.print(ay);
  Serial.println(" g");

  Serial.print("Acceleration Z: ");
  Serial.print(az);
  Serial.println(" g");

  Serial.println();

  Serial.print("Angular Velocity X: ");
  Serial.print(gx);
  Serial.println(" °/s");

  Serial.print("Angular Velocity Y: ");
  Serial.print(gy);
  Serial.println(" °/s");

  Serial.print("Angular Velocity Z: ");
  Serial.print(gz);
  Serial.println(" °/s");

  Serial.println();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.println("-----------------------------");

  delay(1000);
}