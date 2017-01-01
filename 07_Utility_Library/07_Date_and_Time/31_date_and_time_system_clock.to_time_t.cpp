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
//  static std::time_t to_time_t (const time_point& t)
//
//  Converts 't' to a std::time_t type.
//  If the std::time_t has lower precision,it is implementation-defined
//  whether the value is rounded or truncated.


#include <iostream>
#include <chrono>
#include <ctime>

int main (){

    std::chrono::time_point< std::chrono::system_clock > clock_now = std::chrono::system_clock::now();

    std::time_t c_clock_now = std::chrono::system_clock::to_time_t( clock_now );

    std::cout << std::asctime( std::localtime( &c_clock_now )) << std::endl;

}

/* output for me:

Tue Dec 13 11:59:00 2016

*/


