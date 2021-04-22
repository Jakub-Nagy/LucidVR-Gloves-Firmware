/*!
*    @file SerialBTCommunication.ino 
*
*    @section Introduction
*
*    This file is a part of the LucidGloves Firmware Version 2. It is used to operate
*    the LucidVR haptic gloves.
*
*    This specific header is used to interface the bluetooth radio.
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


// Only compiles for the ESP32
#ifdef COMM_BTSERIAL
    #include "BluetoothSerial.h"
    class BTSerialCommunication : public ICommunication {
      private:
        bool m_isOpen;
        BluetoothSerial m_SerialBT;
        
      public:
        BTSerialCommunication() {
          m_isOpen = false;
        }

        bool isOpen(){
          return m_isOpen;
        }

        void start(){
          Serial.begin(115200);
          m_SerialBT.begin(BTSERIAL_DEVICE_NAME);
          Serial.println("The device started, now you can pair it with bluetooth!");
          m_isOpen = true;
        }

        void output(char* data){
          m_SerialBT.print(data);
        }
    };
#endif