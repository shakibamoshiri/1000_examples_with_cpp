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
/// std::chrono::system_clock::now
//  static std::chrono::time_point< std::chrono::system_clock> now ();
//
//  Returns a time point representation the current point in time.


#include <iostream>
#include <chrono>
#include <thread>

void function (){
    std::this_thread::sleep_for( std::chrono::seconds(1) );
} // end of the function()


int main (){

    auto beginning = std::chrono::system_clock::now();
    function();
    auto end = std::chrono::system_clock::now();

    // std::chrono::duration<long long int, std::ratio<1ll, 1000000000ll> >  time_to_finish = (end - beginning);
    // std::chrono::duration< double >  time_to_finish = (end - beginning);

    std::cout << "running the function() lasted "
              << std::chrono::duration< double >( end - beginning ).count()
              << " second\n";
}

/* output for me:

running the function() lasted 1.00007 second

*/


