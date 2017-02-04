/*
    quick review:
    General-Purpose Utility

    01. program utility
    02. date and time
    03. bitset
    04. function object
    05. pair
    06. tuple
    07. swap, forward, move
    08. type operations
    09. hash support

*/
/// 02. data and time ( c++ ) in header <chrono>

//  clock
//      system_clock            -> wall clock
//          now
//          to_time_t
//          form_time_t
//
//      stead_clock             -> monotonic clock
//          now
//
//      high_resolution_clock   -> the shortest tick period of time
//          now

#include <iostream>
#include <chrono>
#include <ctime>


int main(){

    typedef std::chrono::_V2::system_clock system_clock;
    typedef std::chrono::time_point< system_clock, std::chrono::nanoseconds > wall_clock;

    // creates new time_point
    wall_clock start = system_clock::now();
//    std::time_t now = system_clock::to_time_t( start );
    // or
    std::time_t now = std::chrono::duration_cast< std::chrono::seconds >( start.time_since_epoch() ).count();
    std::cout << now;   // time since epoch

}


/* output:

1485776992

*/

/* in standard library: <chrono>

    /// nanoseconds
    typedef duration<int64_t, nano> 	    nanoseconds;

    /// microseconds
    typedef duration<int64_t, micro> 	    microseconds;

    /// milliseconds
    typedef duration<int64_t, milli> 	    milliseconds;

    /// seconds
    typedef duration<int64_t> 		        seconds;

    /// minutes
    typedef duration<int64_t, ratio< 60>>   minutes;

    /// hours
    typedef duration<int64_t, ratio<3600>>  hours;

*/
