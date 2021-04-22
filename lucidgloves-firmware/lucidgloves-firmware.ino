/*!
*    @file lucidgloves-firmware.ino 
*
*    @section Introduction
*
*    This file is a part of the LucidGloves Firmware Version 2. It is used to operate
*    the LucidVR haptic gloves.
*
*    This specific header is used as a configuration file. Follow the instructions in the comments to set up you device.
*
*    @section Dependencies
*
*    1) lucidgloves-firmware.h - project configuration file, should be present within the project.
*
*    @author Author
*
*    Software developed by Lucas_VRTech - LucidVR <lucidvrtech.com>.
*    Modified by Jakub Nagy <https://github.com/Jakub-Nagy>.
*
*    @section Documentation
*
*    Documentation and the source repo for this project can be found at <https://github.com/LucidVR/lucidgloves-hardware>
*/


// Device based configuration 
#if defined (__AVR__)
    // Arduino nano default pinout (change pins below if you have different connections)
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

    // Maximum analog value for Arduino
    #define ANALOG_MAX 1023 

    // Default communication port settings for Arduino
    #define COMM_SERIAL
    #define SERIAL_BAUD_RATE 115200
#elif defined(ESP8266) || defined(ESP32)
    // ESP32 default pinout (change pins below if you have different connections)
    #define PIN_PINKY     1
    #define PIN_RING      2
    #define PIN_MIDDLE    3
    #define PIN_INDEX     4
    #define PIN_THUMB     5
    #define PIN_JOY_X     6
    #define PIN_JOY_Y     7
    #define PIN_JOY_BTN   8 
    #define PIN_A_BTN     9 
    #define PIN_B_BTN     10
    #define PIN_TRIG_BTN  11 // unused if gesture set
    #define PIN_GRAB_BTN  12 // unused if gesture set
    #define PIN_PNCH_BTN  13 // unused if gesture set

    // Maximum analog value for EPS32
    #define ANALOG_MAX 4095

    // Default communication port settings for ESP32
    #define COMM_BTSERIAL
    #define BTSERIAL_DEVICE_NAME "ESP32test"
    #define SERIAL_BAUD_RATE 115200 
#endif


// Generic Configuration settings
#define DEBUG_LED LED_BUILTIN
#define LOOP_TIME 4 // How much time between data sends (ms), set to 0 for a good time :)
#define CALIBRATION_LOOPS 5000 // How many loops should be calibrated. Set to -1 to always be calibrated.

// Analog input configuration
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
