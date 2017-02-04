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

    // arithmetic operators that was overloaded for chrono library
    // + - * / %
    // ++ --
    // += -+ *= /= %=
    // == != <= >= < >

    one_sec = one_sec + one_sec;
    std::cout << one_sec.count() << '\n';   // 2

    ++one_min;
    std::cout << one_min.count() << '\n';   // 2

    one_hour += one_hour;
    // error:
//    one_hour += 1;
    std::cout << one_hour.count() << '\n';  // 2
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
