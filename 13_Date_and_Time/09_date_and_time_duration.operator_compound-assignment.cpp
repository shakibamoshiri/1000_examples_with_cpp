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
/// std::chrono:duration:: operator ++ and ++(int) and -- and --(int)
//  duration& operator += (const duration&)     // 1
//  duration& operator -= (const duration&)     // 2
//  duration& operator *= (const rep&)          // 3
//  duration& operator /= (const rep&)          // 4
//  duration& operator %= (const rep&)          // 5
//  duration& operator %= (const duration&)     // 6
//
//  Performs compound assignment between two duration with the same
//  period or between a duration and a tick count value.

#include <iostream>
#include <chrono>


int main (){

    std::chrono::minutes m (10);    // 10 minutes
    m *= 2;                         // 20 minutes

    m += std::chrono::hours(10);    // hours implicitly convert to minutes

    std::cout << m.count()
              << " minutes equals "
              << std::chrono::duration_cast<std::chrono::hours>(m).count()
              << " hours and "; // continuous at below:

              m %= std::chrono::hours(1);   // 620 %= 60 -> 10.333

              std::cout << m.count() << " minutes\n";

}

/* output for me:

620 minutes equals 10 hours and 20 minutes

*/
