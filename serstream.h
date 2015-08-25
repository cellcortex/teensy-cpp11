#ifndef __SERSTREAM_H
#define __SERSTREAM_H

#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <streambuf>


template <class charT, class traits, class Tserial>
class basic_serialbuf : public std::basic_streambuf<charT, traits>
{
public:

    /*
     * Types used here
     */

    typedef charT char_type;
    typedef typename traits::int_type int_type;

    /*
     * constructor - wraps an existing Tserial class instance
     */

    explicit basic_serialbuf(Tserial& serial_,std::ios_base::openmode which_ = std::ios_base::in | std::ios_base::out)
        : _serial(serial_)
    {
        //std::basic_streambuf<charT,traits>::openedFor = which_;
    }

    /*
     * Required to maintain the chain
     */

    virtual ~basic_serialbuf() { }

    /*
     * Get a reference to the wrapped object
     */

    Tserial& serial() { return _serial; }

protected:

    /*
     * Get how many bytes available
     */

    virtual int showmanyc(){
        return _serial.available();
    }

    /*
     * Read up to n chars
     */

    virtual std::streamsize xsgetn(char_type* c, std::streamsize n) {

        std::streamsize i = 0;
        char_type data;

        while((data=_serial.read())!=-1 && i < n ) {
            c[i] = data;
            ++i;
        }
        return i;
    }

    /*
     * Write up to n chars
     */

    virtual std::streamsize xsputn(const char_type* s, std::streamsize n){

        for(std::streamsize i=0;i<n;i++)
            _serial.print(s[i]);

        return n;
    }

    /*
     * write a single char
     */

    virtual int_type overflow (int_type c = traits::eof()) {
        if(!traits::eq_int_type(c,traits::eof()))
            _serial.print((char_type)c);

        return traits::not_eof(c);
    }


    /*
     * peek at a char where possible
     */

    virtual int_type underflow(){
        if(_serial.available())
            return _serial.peek();
        else 
            return traits::eof();
    }

    /*
     * Read a char where possible
     */

    virtual int_type uflow(){
        if(_serial.available())
            return _serial.read();
        else 
            return traits::eof();
    }

    /*
     * Our wrapped arduino class
     */

    Tserial _serial;
};

/*
 * Output stream
 */

template <class charT, class traits, class Tserial> class basic_oserialstream
: public std::basic_ostream<charT,traits>
{
public:

    /*
     * Types used here
     */

    typedef charT char_type;

    /*
     * Constructor - default the serial object to #1
     * Mega users can explicity initialise with one of
     * the others
     */

    explicit basic_oserialstream(Tserial& serial_)
        : std::basic_ios<charT, traits>(&sb), std::basic_ostream<charT,traits>(&sb), sb(serial_,std::ios_base::out)
    {
    }

    /*
     * Required to maintain the chain
     */

    virtual ~basic_oserialstream() {  }

    /*
     * Initialise the baud rate
     */

    void begin(long speed_) {
        sb.serial().begin(speed_);
    }

    /*
     * The wrapped object
     */

private:
    basic_serialbuf<charT,traits,Tserial> sb;
};


/*
 * Input stream
 */

template <class charT, class traits, class Tserial> class basic_iserialstream
: public std::basic_istream<charT,traits>
{
public:

    /*
     * Types used here
     */

    typedef charT char_type;

    /*
     * Constructor - default the serial object to #1
     * Mega users can explicity initialise with one of
     * the others
     */

    explicit basic_iserialstream(Tserial& serial_)
        : std::basic_ios<charT, traits>(&sb), std::basic_istream<charT,traits>(&sb), sb(serial_,std::ios_base::in)
    {
    }

    /*
     * Required to maintain the chain
     */

    virtual ~basic_iserialstream() {  }

    /*
     * Initialise the baud rate
     */

    void begin(long speed_) {
        sb.serial().begin(speed_);
    }

    /*
     * The wrapped object
     */

private:
    basic_serialbuf<charT,traits,Tserial> sb;
};

/*
 * Input/output stream
 */

template <class charT, class traits, class Tserial> class basic_ioserialstream
: public std::basic_iostream<charT,traits>
{
public:

    /*
     * Types used here
     */

    typedef charT char_type;

    /*
     * Constructor - default the serial object to #1
     * Mega users can explicity initialise with one of
     * the others
     */

    explicit basic_ioserialstream(Tserial& serial_)
        : std::basic_ios<charT, traits>(&sb), std::basic_iostream<charT,traits>(&sb), sb(serial_,std::ios_base::in | std::ios_base::out)
    {
    }

    /*
     * Required to maintain the chain
     */

    virtual ~basic_ioserialstream(){  }

    /*
     * Initialise the baud rate
     */

    void begin(long speed_) {
        sb.serial().begin(speed_);
    }

    /*
     * The wrapped object
     */

private:
    basic_serialbuf<charT, traits, Tserial> sb;
};


#endif

