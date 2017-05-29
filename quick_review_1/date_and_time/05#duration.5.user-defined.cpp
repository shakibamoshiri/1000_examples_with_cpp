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

    std::chrono::duration< int64_t > one_sec( 1 );
    std::chrono::duration< int64_t, std::ratio< 60 > > one_min( 1 );
    std::chrono::duration< int64_t, std::ratio< 3660 > > one_hour( 1 );

    std::cout << std::chrono::duration_cast< std::chrono::seconds >( one_sec ).count() << '\n';
    std::cout << std::chrono::duration_cast< std::chrono::seconds >( one_min ).count() << '\n';
    std::cout << std::chrono::duration_cast< std::chrono::seconds >( one_hour ).count() << '\n';

    // As you can see you can can cast the user-defined time to what you want
    // the real syntax is this:
    std::cout << std::chrono::duration_cast< std::chrono::duration< int64_t > >( one_sec ).count() << '\n';
    std::cout << std::chrono::duration_cast< std::chrono::duration< int64_t > >( one_min ).count() << '\n';
    std::cout << std::chrono::duration_cast< std::chrono::duration< int64_t > >( one_hour ).count() << '\n';
    // I put them here so that you see the real syntax and tell you do not scared of the style of it
    // the style is a little scary
    // but if you play with them, after a little time you will comfort

}


/* output:

1
60
3660
1
60
3660

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
