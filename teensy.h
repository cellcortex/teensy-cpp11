#ifndef __TEENSY_H
#define __TEENSY_H

#include "serstream.h"

template <class charT, class traits = std::char_traits<charT>, class Tserial=usb_serial_class> class basic_serialbuf;
template <class charT, class traits = std::char_traits<charT>, class Tserial=usb_serial_class> class basic_iserialstream;
template <class charT, class traits = std::char_traits<charT>, class Tserial=usb_serial_class> class basic_oserialstream;

typedef basic_iserialstream<char> iserial;
typedef basic_oserialstream<char> oserial;



#endif

