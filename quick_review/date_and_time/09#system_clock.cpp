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
#include <unistd.h>


int main(){

    // time_point is a template class, with two parameter-list
    // nanoseconds is default duration for system_clock
    // 1. std::chrono::_V2::system_clock
    // 2. std::nano
    std::chrono::time_point< std::chrono::_V2::system_clock, std::chrono::nanoseconds > start = std::chrono::_V2::system_clock::now();  // return time_point
//    auto now = std::chrono::_V2::system_clock::now();  // return time_point

    sleep( 1 );         // one second
    // or:
    usleep( 1000000 );  // one second

    std::chrono::time_point< std::chrono::_V2::system_clock, std::chrono::nanoseconds > finish = std::chrono::_V2::system_clock::now();  // return time_point

    std::cout << ( finish - start ).count() << '\n'; // 2000161041


}


/* output:



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
