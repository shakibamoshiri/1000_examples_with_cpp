/*
            Date and Time
            *************

    1. duration
        see the examples from 01 to 28
    -----------------------------------
    2. Clocks:
        see the examples form 29 to 34
    -----------------------------------

    3. Time point
    A time point is a duration fo time that had passed since the epoch of specific clock
    (defined in header <chrono>)
    time_point

        Member types
        Member type 	Definition
        clock 	        Clock, the clock on which this time point is measured
        duration 	    Duration, a std::chrono::duration type used to measure the time since epoch
        rep 	        Rep, an arithmetic type representing the number of ticks of the duration
        period 	        Period, a std::ratio type representing the tick period of the duration

        Member functions
        (constructor)       constructs a new time point
        time_since_epoch    returns the time point as duration since the start of its clock
        operator+=
        operator-=          modifies the time point by the given duration
        min                 returns the time point corresponding to the smallest duration
        max                 returns the time point corresponding to the largest duration

        Non-member functions
        std::common_type<std::chrono::time_point>       specializes the std::common_type trait

        operator+
        operator-   modifies the time point by the given duration

        operator==
        operator!=
        operator<
        operator<=
        operator>
        operator>=  compares two time points

        time_point_cast                     converts a time point to another time point on the same clock, with a different duration
        floor(std::chrono::time_point)      converts a time_point to another, rounding down
        ceil(std::chrono::time_point)       converts a time_point to another, rounding up
        round(std::chrono::time_point)      converts a time_point to another, rounding to nearest, ties to even



*/
/// std::chrono::time_point operator + and operator -
//
//  Performs add and subtract operations involving a time_point.


#include <iostream>
#include <chrono>
#include <ctime>

// #include <unistd.h>


int main (){

    typedef std::chrono::time_point< std::chrono::system_clock > tp_sys_clock;

    // time of the epoch
    tp_sys_clock today;                             // Thu Jan  1 03:30:00 1970

    // update the time to now
    today = std::chrono::system_clock::now();       // Thu Dec 14 12:42:28 2016

    // adding | operator +
    today = today + (std::chrono::hours( 24 ));     // Thu Dec 15 12:42:28 2016
    std::time_t ct = std::chrono::system_clock::to_time_t(today);
    std::cout << std::ctime( &ct );                 // Thu Dec 15 12:42:28 2016

    // subtracting | operator -
    today = today - (std::chrono::hours( 48 ));     // Thu Dec 13 12:42:28 2016
    ct = std::chrono::system_clock::to_time_t(today);
    std::cout << std::ctime( &ct );                 // Thu Dec 13 12:42:28 2016



}


/* output for me:

*/


