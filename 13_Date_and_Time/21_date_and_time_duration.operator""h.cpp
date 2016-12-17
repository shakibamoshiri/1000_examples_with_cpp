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
/// operator""h (for hour)
//  Forms a std::chrono::duration literal representing hours
//
/// NOTE:
//  These operator are declared in the namespace std::literal::chrono_literals,
//  where both literals and chrono_literal are inline namespaces.
//  Access to these operators can be gained with using namespace std::literals::chrono_literals.

#include <iostream>
#include <chrono>
#include <thread>

int main (){

    using namespace std::literals::chrono_literals;
    // also correct:
    // using namespace std::chrono_literals;

    std::chrono::duration< unsigned int, std::ratio<3600, 1> > day = 24h;
    // or
    // std::chrono::duration< unsigned int, std::ratio<3600> > day = 24h;
    // or:
    // auto day = 24h;

    std::chrono::duration< double, std::ratio<3600, 1> > half_an_hour = 0.5h;
    // or:
    // auto half_an_hour = 0.5h

    std::cout << "one day is: "
              << day.count() << '\n'
              << "and half an hour is: "
              << half_an_hour.count() << '\n';
}

/* output for me:

one day is: 24
and half an hour is: 0.5
*/

/// some useful information:
//  std::chrono::duration
//  hours	        signed integral type of at least 23 bits	ratio<3600,1>
//  minutes	        signed integral type of at least 29 bits	ratio<60,1>
//  seconds	        signed integral type of at least 35 bits	ratio<1,1>
//  milliseconds	signed integral type of at least 45 bits	ratio<1,1000>
//  microseconds	signed integral type of at least 55 bits	ratio<1,1000000>
//  nanoseconds	    signed integral type of at least 64 bits	ratio<1,1000000000>

