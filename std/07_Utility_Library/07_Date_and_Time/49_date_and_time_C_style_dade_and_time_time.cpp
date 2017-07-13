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
/// std::time
//  std::time_t time (std::time_t* arg)
//
//  Returns the current calender time encoded as a std::time_t
//  object, and also stores it in the object pointed to by arg;



#include <iostream>
#include <ctime>

// #include <chrono>
// #include <unistd.h>


int main (){
    std::time_t today = std::time( nullptr );   // or std::time( 0 ) or std::time( NULL )

    std::cout << std::asctime( std::localtime( &today ) ) << '\n';
    std::cout << today << " seconds since the Epoch\n";
}


/* output for me:

Wed Dec 14 15:30:48 2016
*/


