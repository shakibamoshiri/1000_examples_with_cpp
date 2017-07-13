/*
            Date and Time
            *************

    1. duration
        see the examples from 01 to 28
    -----------------------------------

    2. Clocks:
    A clock consist of a starting point (or epoch) and a tick rate. For example, a clock
    may have an epoch of January 1, 1970 and tick every second. C++ defines three clock types:

        2.1 system_clock
            Member types
            rep 	    signed arithmetic type representing the number of ticks in the clock's duration
            period 	a   std::ratio type representing the tick period of the clock, in seconds
            duration 	std::chrono::duration<rep, period>, capable of representing negative durations
            time_point 	std::chrono::time_point<std::chrono::system_clock>

            Member constants
            constexpr bool is_steady    true if the time between ticks is always constant, i.e. calls to now()
                                        return values that increase monotonically even in case of some external clock adjustment

            Member functions
            > now             returns a std::chrono::time_point representing the current point in time
            > to_time_t       converts a system clock time point to std::time_t
            > from_time_t     converts std::time_t to a system clock time point
*/
/// std::chrono::system_clock::to_time_t
//  static std::chorno::system_clock::time_point from_time_t (std::time_t)
//
//  Converts 't' to time point type, using the coarser precision of the two types.
//  If the std::time_t has lower precision,it is implementation-defined
//  whether the value is rounded or truncated.


#include <iostream>
#include <chrono>
#include <ctime>

int main (){

    // C-style time point
    std::time_t c_clock_now = std::time( nullptr );

    // covert a C-style time-point to C++ time-point
    std::chrono::time_point< std::chrono::system_clock > cpp_clock_now = std::chrono::system_clock::from_time_t( c_clock_now );

}

/* output for me:



*/


