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
/// std::chrono::time_point::time_point
//  Constructs a new time_point from one of several optional data source.



#include <iostream>
#include <chrono>
// #include <unistd.h>

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point< Clock >;

void print_ms (const TimePoint& point){

    using Ms = std::chrono::milliseconds;
    const Clock::duration since_epoch = point.time_since_epoch();

    std::cout << std::chrono::duration_cast< Ms >(since_epoch).count() << " ms\n";

} // end of point_ms function


int main (){

    const TimePoint default_value = TimePoint();    // (1);
    print_ms( default_value );                      // 0 ms

    const Clock::duration _4_seconds_duratoin = std::chrono::seconds( 4 );
    const TimePoint time_point_4_seconds( _4_seconds_duratoin ); // (2) // using copy constructor
    // four seconds form start of epoch
    print_ms( time_point_4_seconds );

    const TimePoint time_point_now = Clock::now();  // (3)
    print_ms( time_point_now );




}

/* output for me:

0 ms
4000 ms
1481623167171 ms

*/


