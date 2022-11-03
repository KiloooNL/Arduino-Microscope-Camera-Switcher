
# Arduino Microscope Camera Switcher

This Arduino script reads the magnetic field values from the LSM9DS1 sensor and then performs a keypress based on the X and Z co-ordinates.

The project is based off of Paul Daniel's Compass Switch project: https://github.com/inflex/compass-switch

Instead of using the HMC5833L IC, I opted to use an Arduino Nano.
This project is intended to have the Arduino on the microscope, and when the microscope is moved to a certain position a keypress will result. Essentially creating an automatic vision switcher with OBS or similar when the microscope is in-view.


  The hardware:
  - Arduino Nano 33 BLE: https://core-electronics.com.au/arduino-nano-33-ble.html

  Libraries used: 
  - Arduino LSM9DS1: https://www.arduino.cc/reference/en/libraries/arduino_lsm9ds1/
  - Pluggable USB HID: https://www.arduino.cc/reference/en/libraries/usbhid/
  - USB Keyboard: https://github.com/julianschuler/USBKeyboard
