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

//  duration

#include <iostream>
#include <chrono>
#include <cstdint>  // fixed size integer


int main(){

    // literal helper function
    using namespace std::literals::chrono_literals;
    // operator h   for hours
    // operator min for minutes
    // operator s   for seconds
    // operator ms  for milliseconds
    // operator us  for microseconds
    // operator ns  for nanoseconds

    auto one_hour = 1h;
    std::chrono::duration< int64_t > one_second;    // by default: std::ratio< 1, 1 >
    one_second = one_hour;
    std::cout << one_second.count() << '\n';        // 3600


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
