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
/// std::chrono::duration duration_cast
//  Converts a std::chorno::duration to a duration of different type.
//
/// NOTE:
//  The function does not participate in the overload resolution
//  unless ToDuration (parameter) is in instance of std::chrono::duration
//
//  Casting between floating-point durations or between integer duration
//  where the source period is exactly divided by the target period
//  (e.g. hours to minutes) cab be preformed implicitly, no duration_cast
//  is needed.
//  Casting a floating-point duration to an integer duration is subject
//  undefined behavior when the floating-point value is NaN, infinity, or too
//  large to be representable by the target's integer type.

#include <iostream>
#include <chrono>
#include <thread>

void function (){ std::this_thread::sleep_for( std::chrono::seconds(1) ); } // sleeping for 1 second

int main (){

    // measures the execution time of a function "function"
    auto t1 = std::chrono::high_resolution_clock::now();
    function();
    auto t2 = std::chrono::high_resolution_clock::now();

    // NOTE: auto equals
    // std::chrono::time_point<std::chrono::high_resolution_clock> t1
    // std::chrono::time_point<std::chrono::high_resolution_clock> t2

    std::cout << "function() took "
              << std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count()
              << " milliseconds" << std::endl;
}

/* output for me:

function() took 1000 milliseconds

*/
