/*!
*    @file Config.h 
*
*    @section Introduction
*
*    This file is a part of the LucidGloves Firmware Version 2 ported to PlatformIO. It is used to operate
*    the LucidVR haptic gloves.
*
*    This specific header is used as a configuration file. Follow the instructions in the comments to set up you device.
*    Remember that configuring things like the MCU (development board) or the terminal (serial monitor) speed is done in the platformio.ini file.
*
*    @section Dependencies
*
*    1) Arduino.h - the Arduino framework. Is already present inside of PlatformIO.
*    2) Config.h - project configuration file, should be present within the project.
*
*    @author Author
*
*    Software developed by Lucas_VRTech - LucidVR <lucidvrtech.com>.
*    Ported to PlatformIO by Jakub Nagy <https://github.com/Jakub-Nagy>.
*
*    @section Documentation
*
*    Documentation and the source repo for this project can be found at <https://github.com/LucidVR/lucidgloves-hardware>
*/

// CONFIGURATION SETTINGS
#define DEBUG_LED LED_BUILTIN
#define COMMUNICATION COMM_SERIAL //Which communication protocol to use

#define LOOP_TIME 4 // How much time between data sends (ms), set to 0 for a good time :)
#define CALIBRATION_LOOPS 5000 // How many loops should be calibrated. Set to -1 to always be calibrated.

// Uncomment the following in order to use serial over USB
#define COMM_SERIAL
#define SERIAL_BAUD_RATE 115200

// Uncomment the following in order to use serial over Bluetooth  (Work in progress)
// #define COMM_BTSERIAL
// #define BTSERIAL_DEVICE_NAME "ESP32test"
// #define SERIAL_BAUD_RATE 115200

// PINS CONFIGURATION 
// (This configuration is for Arduino Nano so make sure to change if you're on another board)
#define PIN_PINKY     A0
#define PIN_RING      A1
#define PIN_MIDDLE    A2
#define PIN_INDEX     A3
#define PIN_THUMB     A4
#define PIN_JOY_X     A6
#define PIN_JOY_Y     A7
#define PIN_JOY_BTN   7 
#define PIN_A_BTN     8 
#define PIN_B_BTN     9
#define PIN_TRIG_BTN  10 // unused if gesture set
#define PIN_GRAB_BTN  11 // unused if gesture set
#define PIN_PNCH_BTN  12 // unused if gesture set

// ANALOG INPUT CONFIG
#define ANALOG_MAX 1023   // Set to 1023 on Arduino, 4095 on ESP32
#define FLIP_POTS  false  // Flip values from potentiometers (for fingers!) if they are backwards

// Gesture enables, make false to use button override
#define TRIGGER_GESTURE true
#define GRAB_GESTURE    true
#define PINCH_GESTURE   true

// Joystick configuration
#define JOYSTICK_BLANK true
#define JOY_FLIP_X false
#define JOY_FLIP_Y false

#define NO_THUMB false // If for some reason you don't want to track the thumb