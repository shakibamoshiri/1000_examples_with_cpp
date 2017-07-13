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
#include <vector>
#include <numeric>


int main (){

    volatile int sink(0);


    typedef std::chrono::duration<int64_t, std::nano> nano_second;
    typedef std::chrono::time_point< std::chrono::system_clock, nano_second > time_point_t;

    /// for why I am using this typedef, see chrono implementation
    /*  about line 716:

        struct system_clock
    {
      typedef chrono::nanoseconds     				duration;
      typedef duration::rep    					rep;
      typedef duration::period 					period;
      typedef chrono::time_point<system_clock, duration> 	time_point;

      ...

    if you realized, the std::chrono::system_clock::now() return something like this:
        chrono::time_point<system_clock, duration>

        what is duration? --------> typedef std::chrono::duration<int64_t, std::nano>
        whit is system_clock -----> its struct system_clock

        so I need a type like this:
        std::chrono::time_point< std::chrono::system_clock, std::chrono::duration<int64_t, std::nano> >
    */

    for (unsigned long long size = 1ull;
         size < 1000000000ull;
         size *= 100){
             // recored starting time:
             time_point_t starting = std::chrono::system_clock::now();

             // doing something:
             std::vector<int>  vector( size , 100 );
             sink = std::accumulate( vector.begin(), vector.end(), 0u);

             // recored ending time:
             time_point_t ending = std::chrono::system_clock::now();

             std::chrono::duration< double > different_time = (ending - starting);

             // printing
             std::cout <<  "time to fill and iterate a vector of "
                       << size << " ints: "
                       << different_time.count() << '\n';

         } // the end of the for loop
}

/* output for me:

time to fill and iterate a vector of 1 ints: 1.657e-06
time to fill and iterate a vector of 100 ints: 7.76e-07
time to fill and iterate a vector of 10000 ints: 4.145e-05
time to fill and iterate a vector of 1000000 ints: 0.00748767
time to fill and iterate a vector of 100000000 ints: 0.658763

*/


