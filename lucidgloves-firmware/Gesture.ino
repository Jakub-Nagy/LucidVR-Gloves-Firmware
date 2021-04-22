/*!
*    @file Gesture.ino 
*
*    @section Introduction
*
*    This file is a part of the LucidGloves Firmware Version 2. It is used to operate
*    the LucidVR haptic gloves.
*
*    This specific header is used to process the gestures made by the user of the gloves.
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

bool grabGesture(int *flexion){
  return (flexion[0] + flexion[1] + flexion[2] + flexion[3]) / 4 <= ANALOG_MAX/2 ? 0:1;
}

bool pinchGesture(int *flexion){
  return (flexion[0] + flexion[1]) / 2 <= ANALOG_MAX/2 ? 0:1;
}

bool triggerGesture(int *flexion){
  return flexion[1]<=(1023/2)?0:1;
}