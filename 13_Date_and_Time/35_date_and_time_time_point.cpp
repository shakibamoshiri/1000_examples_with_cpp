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
/// std::chrono::time_point
//  A time point is a duration fo time that had passed since the epoch of specific clock



#include <iostream>
#include <chrono>
// #include <unistd.h>

long fibonacci( unsigned n ){

    if (n < 2) return n;

    return fibonacci( n - 1 ) + fibonacci( n - 2 );

} // end of fibonacci function

int main (){

    // create to time_point
    std::chrono::time_point< std::chrono::system_clock > start, end;

    start = std::chrono::system_clock::now();
    std::cout << "Fibonacci (32) == " << fibonacci(32) << std::endl;
    end = std::chrono::system_clock::now();

    std::chrono::duration< double > different_time = (end - start); // per second

    std::time_t c_end_time = std::chrono::system_clock::to_time_t( end ); // C++ style to C style

    std::cout << "finishing computation at "
              << std::ctime( &c_end_time )
              << "and different_time is: "
              << different_time.count() << '\n';



}

/* output for me:

Fibonacci (32) == 2178309
finishing computation at Tue Dec 13 13:12:41 2016
and different_time is: 0.060636

*/


