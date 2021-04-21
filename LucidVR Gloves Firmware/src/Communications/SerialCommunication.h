/*!
*    @file SerialCommunication.h 
*
*    @section Introduction
*
*    This file is a part of the LucidGloves Firmware Version 2 ported to PlatformIO. It is used to operate
*    the LucidVR haptic gloves.
*
*    This specific header is used to interface the USB (serial) port.
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

// Arduino framework
#include <Arduino.h>

// Config file
#include <Config.h>


// Class to handle serial communication over USB
class SerialCommunication : public ICommunication {
  private:
    bool m_isOpen;

  public:
    SerialCommunication() {
      m_isOpen = false;
    }

    bool isOpen(){
      return m_isOpen;
    }

    void start(){
      Serial.begin(SERIAL_BAUD_RATE);
      m_isOpen = true;
    }

    void output(char* data){
      Serial.print(data);
      Serial.flush();
    }
};