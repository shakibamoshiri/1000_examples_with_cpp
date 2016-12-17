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

        // since C++17
        floor(std::chrono::time_point)      converts a time_point to another, rounding down
        ceil(std::chrono::time_point)       converts a time_point to another, rounding up
        round(std::chrono::time_point)      converts a time_point to another, rounding to nearest, ties to even



*/
/// std::chrono::floor, ceil, round
//  since C++17
//  floor(std::chrono::time_point)      converts a time_point to another, rounding down
//  ceil(std::chrono::time_point)       converts a time_point to another, rounding up
//  round(std::chrono::time_point)      converts a time_point to another, rounding to nearest, ties to even


#include <iostream>
#include <chrono>
#include <ctime>

// #include <unistd.h>


int main (){ /* has no example */ }


/* output for me:

*/


