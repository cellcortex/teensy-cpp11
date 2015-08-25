# Getting C++ 11 and STL on Teensy

This is a guide to get C++ 11 and STL support on Teensy. I've also added a
serial stream class so you can use the C++ stream operators on the serial port.

Getting C++ 11 for Arduino
From http://stackoverflow.com/questions/16224746/how-to-use-c11-to-program-the-arduino

edit the boards.txt (or the platform.txt) file. For me this was in
'/Applications/Arduino.app/Contents/Java/hardware/teensy/avr/boards.txt'


    teensy31.build.flags.cpp=-fno-exceptions -felide-constructors -std=gnu++11 -fno-rtti

    teensy31.build.flags.libs=-larm_cortexM4l_math -lm -lstdc++



