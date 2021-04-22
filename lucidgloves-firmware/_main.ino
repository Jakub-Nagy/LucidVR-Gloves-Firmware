/*!
*    @file _main.ino 
*
*    @section Introduction
*
*    This file is a part of the LucidGloves Firmware Version 2. It is used to operate
*    the LucidVR haptic gloves.
*
*    This is the main runtime file of this program. It includes and invokes all the project classes.
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


#define ALWAYS_CALIBRATING CALIBRATION_LOOPS == -1
ICommunication* comm;
int loops = 0;

void setup() {
  #if defined(COMM_SERIAL)
    comm = new SerialCommunication();
  #elif defined (COMM_BTSERIAL)
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
