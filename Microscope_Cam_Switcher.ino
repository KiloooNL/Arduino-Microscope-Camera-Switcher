/*
  This code reads the magnetic field values from the LSM9DS1
  sensor and then performs a keypress based on the X, Z co-ordinates

  The circuit:
  - Arduino Nano 33 BLE Sense

  created 15 Feb 2022
  by Ben / KiloooNL
  https://github.com/KiloooNL/Arduino-Microscope-Camera-Switcher
*/

#include <Arduino_LSM9DS1.h>
#include "PluggableUSBHID.h"
#include "USBKeyboard.h"

USBKeyboard key;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Magnetic field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" uT");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(x, y, z);

    // Print the XYZ cords
    delay(1000);
    if(x < 25 && z > 35) {
      Serial.print(x);
      Serial.print("\t");
      Serial.print(z);
      Serial.println(" - Microscope is away");
      key.key_code(KEY_SCROLL_LOCK);
    } else if(x > 25 && z < 35 || x < 20 && z < 32 && z > 29) {
      Serial.print(x);
      Serial.print("\t");
      Serial.print(z);
      Serial.println(" - Microscope is out");
      key.key_code(KEY_INSERT);
    } else {
      Serial.print(x);
      Serial.print("\t");
      Serial.print(z);
      Serial.println(" - Outside of range. Check cords.");
    }
  }
}
