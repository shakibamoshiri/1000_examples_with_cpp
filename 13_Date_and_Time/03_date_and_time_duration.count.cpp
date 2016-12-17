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
/// std::chrono:duration:count
//  constexpr tep count() const;
//
//  Returns the number of ticks for this duration.

#include <iostream>
#include <chrono>


int main (){

    std::chrono::milliseconds ms (3);       // 3 milliseconds

    // 6000 microseconds, constructs form 3 milliseconds
    std::chrono::microseconds us = 2 * ms;

    // 30Hz clock using fractional ticks
    std::chrono::duration<double, std::ratio<1,30>> hz30 (3.5);

    std::cout << "3 ms duration has: "     << ms.count()   << " ticks\n"
              << "6000 us duration has: "  << us.count()   << " ticks\n"
              << "3.5 30Hz duration has: " << hz30.count() << " tick\n";

}

