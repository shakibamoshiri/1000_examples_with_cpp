/*
            Date and Time
            *************

    1. duration
        (constructor)   constructs new duration
        operator=       assigns the contents
        count           returns the count of ticks
        zero            returns the special duration value zero
        min             returns the special duration value min
        max             returns the special duration value max
        operator+
        operator-	        implements unary + and unary -
        operator++
        operator++(int)
        operator--
        operator--(int)     increments or decrements the tick count
        operator+=
        operator-=
        operator*=
        operator/=
        operator%=  	    implements compound assignment between two durations

        Non-member functions
        std::common_type<std::chrono::duration>                 specializes the std::common_type trait
        operator+
        operator-
        operator*
        operator/
        operator%           implements arithmetic operations with durations as arguments

        operator==
        operator!=
        operator<
        operator<=
        operator>
        operator>=      compares two durations

        duration_cast   converts a duration to another, with a different tick interval

        floor(std::chrono::duration)    converts a duration to another, rounding down
        ceil(std::chrono::duration)     converts a duration to another, rounding up
        round(std::chrono::duration)    converts a duration to another, rounding to nearest, ties to even
        abs(std::chrono::duration)      obtains the absolute value of the duration

        Helper types
        Type 	Definition
        std::chrono::nanoseconds 	duration<signed integer type of at least 64 bits, std::nano>
        std::chrono::microseconds 	duration<signed integer type of at least 55 bits, std::micro>
        std::chrono::milliseconds 	duration<signed integer type of at least 45 bits, std::milli>
        std::chrono::seconds 	    duration<signed integer type of at least 35 bits>
        std::chrono::minutes 	    duration<signed integer type of at least 29 bits, std::ratio<60>>
        std::chrono::hours 	        duration<signed integer type of at least 23 bits, std::ratio<3600>>

        Note: each of the predefined duration types covers a range of at least ±292 years.

        Helper classes
        treat_as_floating_point     indicates that a duration is convertible to duration with different tick period
        duration_values             constructs zero, min, and max values of a tick count of given type

        Defined in inline namespace std::literals::chrono_literals
        operator""h             A std::chrono::duration literal representing hours
        operator""min           A std::chrono::duration literal representing minutes
        operator""s             A std::chrono::duration literal representing seconds
        operator""ms            A std::chrono::duration literal representing milliseconds
        operator""us            A std::chrono::duration literal representing microseconds
        operator""ns            A std::chrono::duration literal representing nanoseconds

*/
/// helper type
//  std::chrono::nanoseconds 	duration<signed integer type of at least 64 bits, std::nano>
//  std::chrono::microseconds 	duration<signed integer type of at least 55 bits, std::micro>
//  std::chrono::milliseconds 	duration<signed integer type of at least 45 bits, std::milli>
//  std::chrono::seconds 	    duration<signed integer type of at least 35 bits>
//  std::chrono::minutes 	    duration<signed integer type of at least 29 bits, std::ratio<60>>
//  std::chrono::hours 	        duration<signed integer type of at least 23 bits, std::ratio<3600>>
//
/// NOTE:
//  These operator are declared in the namespace std::literal::chrono_literals,
//  where both literals and chrono_literal are inline namespaces.
//  Access to these operators can be gained with using namespace std::literals::chrono_literals.

#include <iostream>
#include <chrono>


int main (){

    using namespace std::literals::chrono_literals;

    // for hour
    typedef std::chrono::duration< int64_t, std::ratio<3600, 1> > hours;

    // for minute
    typedef std::chrono::duration< int64_t, std::ratio<60, 1> > minutes;

    // for second
    typedef std::chrono::duration< int64_t, std::ratio<1, 1> > seconds;

    // for milliseconds 1/1000
    // typedef std::chrono::duration< int64_t, std::milli > milli_s;
    typedef std::chrono::duration< int64_t, std::ratio<1, 1000> > milli_s;

    // for microseconds 1/1000,000
    // typedef std::chrono::duration< int64_t, std::micro > mirco_s;
    typedef std::chrono::duration< int64_t, std::ratio<1, 1000000> > mirco_s;

    // for nanoseconds 1/1000,000,000
    // typedef std::chrono::duration< int64_t, std::nano > nano_s;
    typedef std::chrono::duration< int64_t, std::ratio<1, 1000000000> > nano_s;


    hours h = 1h;
    minutes m = 1min;
    seconds s = 1s;
    milli_s ms = 1ms;
    mirco_s us = 1ms;
    nano_s ns = 1ns;


    std::cout << h.count() << std::endl;
    std::cout << m.count() << std::endl;
    std::cout << s.count() << std::endl;
    std::cout << ms.count() << std::endl;
    std::cout << us.count() << std::endl;
    std::cout << us.count() << std::endl;

}

/* output for me:

*/

/// some useful information:
//  std::chrono::duration
//  hours	        signed integral type of at least 23 bits	ratio<3600,1>
//  minutes	        signed integral type of at least 29 bits	ratio<60,1>
//  seconds	        signed integral type of at least 35 bits	ratio<1,1>
//  milliseconds	signed integral type of at least 45 bits	ratio<1,1000>
//  microseconds	signed integral type of at least 55 bits	ratio<1,1000000>
//  nanoseconds	    signed integral type of at least 64 bits	ratio<1,1000000000>

