/*
            Date and Time
            *************

    1. duration
        see the examples from 01 to 28
    -----------------------------------
    2. Clocks:
        2.1 system_clock
            see the examples form 29 to 32
            ---------------------------
        2.2 steady_clock
            see the example 33
            ---------------------------
        2.3 high_resolution_clock
            Member types
            Member type 	Definition
            rep 	        arithmetic type representing the number of ticks in the clock's duration
            period 	        a std::ratio type representing the tick period of the clock, in seconds
            duration 	    std::chrono::duration<rep, period>
            time_point 	    std::chrono::time_point<std::chrono::high_resolution_clock>

            Member constants
            constexpr bool is_steady    true if the time between ticks is always constant, i.e. calls to now()
                                        return values that increase monotonically even in case of some external
                                        clock adjustment
            Member functions
            > now             returns a std::chrono::time_point representing the current value of the clock


*/
/// std::chrono::high_resolution_clock
//  Class std::chrono::high_resolution_clock represents the clock
//  with smallest tick period provided by the implementation. It
//  may be an alias of std::chorno::system_clock or std::chorno::steady_clock
//  or third, independent clock.
//
//  std::chrono::high_resolution_clock meets the requirement of TrivialClock
//
/// std::chrono::high_resolution_clock::now
//  static std::chrono::time_point< std::chrono::high_resolution_clock > now();
//
//  Returns a time point representing the current point in time.


#include <iostream>
#include <chrono>
#include <unistd.h>


int main (){

    // getting the time by std::chrono::high_resolution_clock::now
    std::chrono::time_point< std::chrono::_V2::high_resolution_clock > begin_of_time = std::chrono::_V2::high_resolution_clock::now();

    sleep(1);   // from unistd.h

    std::chrono::time_point< std::chrono::_V2::high_resolution_clock > end_of_time = std::chrono::_V2::high_resolution_clock::now();

    std::cout << "we slept for "
              << std::chrono::duration< double >( end_of_time - begin_of_time ).count()
              << " second.\n";

    // or another way to do it
    std::cout << "we slept for "
              << std::chrono::duration_cast<std::chrono::seconds>( end_of_time - begin_of_time ).count()
              << " second.\n";


}

/* output for me:

we slept for 1.00008 second.
we slept for 1 second.

*/


