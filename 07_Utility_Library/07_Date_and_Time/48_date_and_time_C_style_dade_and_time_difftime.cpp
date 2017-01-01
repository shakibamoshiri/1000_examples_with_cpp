/*
            Date and Time
            *************

    1. duration
        see the examples from 01 to 28
    -----------------------------------
    2. Clocks:
        see the examples from 29 to 34
    -----------------------------------
    3. Time point
        see the examples from 35 to 47
    -----------------------------------
    C-style data and time library
    Also provided are the C-style data and time functions, such as std::time_t, std::difftime,
    and CLOCKS_PER_SEC.
        Functions
        Defined in header <ctime>

        Time manipulation
        difftime        computes the difference between times
        time            returns the current time of the system as time since epoch
        clock           returns raw processor clock time since the program is started

        Format conversions
        asctime         converts a tm object to a textual representation
        ctime       	converts a time_t object to a textual representation
        strftime        converts a tm object to custom textual representation
        wcsftime        converts a tm object to custom wide string textual representation
        gmtime          converts time since epoch to calendar time expressed as Universal Coordinated Time
        localtime       converts time since epoch to calendar time expressed as local time
        mktime          converts calendar time to time since epoch

        Constants
        CLOCKS_PER_SEC  number of processor clock ticks per second

        Types
        tm              calendar time type
        time_t          time since epoch type
        clock_t         process running time


*/
/// C-style data and time library
//
/// std::difftime
//  Computes difference between two calender times as  std::time_t
//  objects (time_end - time_beginning) in seconds.
//  If time_end refers to time point before time_beginning, the result is negative.



#include <iostream>
#include <ctime>

// #include <chrono>
// #include <unistd.h>


int main (){
    std::time_t start = std::time( nullptr );   // or std::time( 0 ) or std::time( NULL )
    volatile double d(0.0);                     // initializes by 0.0

    // some time-consuming operation
    for( int n = 0; n < 10000; ++n)
        for( int m = 0; m < 100000; ++m)
            d += n * m;

    std::cout << "wall time passed: " << std::difftime( std::time( nullptr ), start ) << " s\n";
    // it would be like ( end - start )
    // end   -> std::time( nullptr )
    // start -> std::time_t start


}


/* output for me:
wall time passed: 5 s
*/


