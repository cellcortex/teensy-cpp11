#pragma once

#include "serstream.h"

template <class charT, class traits = std::char_traits<charT>, class Tserial=usb_serial_class> class basic_serialbuf;
template <class charT, class traits = std::char_traits<charT>, class Tserial=usb_serial_class> class basic_iserialstream;
template <class charT, class traits = std::char_traits<charT>, class Tserial=usb_serial_class> class basic_oserialstream;

typedef basic_iserialstream<char> iserial;
typedef basic_oserialstream<char> oserial;


// External declaration so STL doesn't bork
extern "C" {
   int _getpid(){ return -1;}
   int _kill(int pid, int sig){ return -1; }
   int _write_r() { return -1; }
}

