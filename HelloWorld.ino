/* Simple "Hello World" example.

   After uploading this to your board, use Serial Monitor
   to view the message.  When Serial is selected from the
   Tools > USB Type menu, the correct serial port must be
   selected from the Tools > Serial Port AFTER Teensy is
   running this code.  Teensy only becomes a serial device
   while this code is running!  For non-Serial types,
   the Serial port is emulated, so no port needs to be
   selected.

   This example code is in the public domain.
 */

#include <vector>
#include <string>
#include "teensy.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_10DOF.h>

/* Assign a unique ID to the sensors */
Adafruit_10DOF                dof   = Adafruit_10DOF();
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_BMP085_Unified       bmp   = Adafruit_BMP085_Unified(18001);


void setup()
{
    Serial.begin(9600); // USB is always 12 Mbit/sec
    std::vector<int> v;
}

void loop()
{
    oserial serial(Serial);
    std::string str;
    char c;

    for(c='A';c<='Z';c++)
        str+=c;

    serial << str << std::endl;
    delay(1000);  // do not print too fast!
}



extern "C"{
int _getpid(){ return -1;}
int _kill(int pid, int sig){ return -1; }
int _write_r() { return -1; }
}
