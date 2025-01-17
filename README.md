# Range Finder Project

## Overview
This project involves creating a distance measurement tool using an Arduino, a LiquidCrystal display, and an HC-SR04 ultrasonic sensor. It measures the distance to an object and displays the status on an LCD based on the distance measured.

## Features
- **Real-time distance measurement**: Measures distances in centimeters and displays them on an LCD screen.
- **Status indicator**: Shows different status messages (`LOW`, `MID`, `HIGH`) on the LCD depending on the distance.
- **Buzzer alerts**: The buzzer turns on for distances less than 50 cm.

## Components Required
- Arduino Board (Uno, Mega, etc.)
- HC-SR04 Ultrasonic Sensor
- LiquidCrystal Display (16x2 LCD)
- Buzzer
- Jumper Wires

## Wiring Instructions
1. **LCD to Arduino**:
   - `RS` pin to digital pin 12
   - `Enable` pin to digital pin 11
   - `D4` to digital pin 5
   - `D5` to digital pin 4
   - `D6` to digital pin 3
   - `D7` to digital pin 2
2. **Ultrasonic Sensor**:
   - `Trig` pin to digital pin 9
   - `Echo` pin to digital pin 8
3. **Buzzer**:
   - One terminal to digital pin 7
   - Other terminal to ground

## Setup
1. Assemble the circuit as per the wiring instructions.
2. Upload the code to your Arduino board.
3. Point the ultrasonic sensor towards an object to get the distance reading.

## How It Works
The ultrasonic sensor emits a high-frequency sound pulse and then listens for its echo. The distance to the object is calculated based on the time it takes for the echo to return.

## Code Description
The `setup()` function initializes the LCD display and the sensor's pins. The `loop()` function continuously measures the distance and updates the LCD and buzzer based on the distance detected.

The display shows:
- `LOW` for distances less than 50 cm (Buzzer ON).
- `MID` for distances between 50 cm and 100 cm.
- `HIGH` for distances greater than 100 cm.
- `ERROR` if no valid distance is measured.

## Conclusion
This range finder can be used for various applications such as robotics, object detection, and automation projects. Its simple design and real-time feedback make it an excellent project for beginners and hobbyists interested in electronics and programming.
