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
#include "Arduino.h"

#include <iterator>
#include <vector>
#include <string>

#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <streambuf>

#include "serstream.h"
#include "teensy.h"

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

    for(c='A'; c<='Z'; c++)
        str+=c;

    serial << str << std::endl;
    delay(1000);  // do not print too fast!
}
