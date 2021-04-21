/*!
*    @file main.cpp 
*
*    @section Introduction
*
*    This file is a part of the LucidGloves Firmware Version 2 ported to PlatformIO. It is used to operate
*    the LucidVR haptic gloves.
*
*    This is the main runtime file of this program. It includes and calls all the project classes.
*
*    @section Dependencies
*
*    1) Arduino.h - the Arduino framework. Is already present inside of PlatformIO.
*    2) Config.h - project configuration file, should be present within the project.
*    2) Input.h - should be present within the project.
*    2) Encoding.h - should be present within the project.
*    2) Gesture.h - should be present within the project.
*    2) ICommunication.h - should be present within the project.
*    2) SerialBTCommunication.h - should be present within the project.
*    2) SerialCommunication.h - should be present within the project.
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

// Arduino framework
#include <Arduino.h>

// Config file
#include <Config.h>

// Project dependencies
#include <Input.h>
#include <Logic/Encoding.h>
#include <Logic/Gesture.h>
#include <Communications/ICommunication.h>
#include <Communications/SerialBTCommunication.h>
#include <Communications/SerialCommunication.h>


#define ALWAYS_CALIBRATING CALIBRATION_LOOPS == -1
ICommunication* comm;
int loops = 0;

void setup() {
  #ifdef COMM_SERIAL
    comm = new SerialCommunication();
  #endif
  #ifdef COMM_BTSERIAL
    comm = new BTSerialCommunication();
  #endif  
  comm->start();

  setupInputs();
}

void loop() {
  if (comm->isOpen()){

    bool calibrate = false;
    if (loops < CALIBRATION_LOOPS || ALWAYS_CALIBRATING){
      calibrate = true;
      loops++;
    }
      
    
    int* fingerPos = getFingerPositions(calibrate);
    bool joyButton = getButton(PIN_JOY_BTN);

    #if TRIGGER_GESTURE
    bool triggerButton = triggerGesture(fingerPos);
    #else
    bool triggerButton = getButton(PIN_TRIG_BTN);
    #endif

    bool aButton = getButton(PIN_A_BTN);
    bool bButton = getButton(PIN_B_BTN);

    #if GRAB_GESTURE
    bool grabButton = grabGesture(fingerPos);
    #else
    bool grabButton = getButton(PIN_GRAB_BTN);
    #endif

    #if PINCH_GESTURE
    bool pinchButton = grabGesture(fingerPos);
    #else
    bool pinchButton = getButton(PIN_PNCH_BTN);
    #endif
    
    comm->output(encode(fingerPos, getJoyX(), getJoyY(), joyButton, triggerButton, aButton, bButton, grabButton, pinchButton));
    delay(LOOP_TIME);
  }
}