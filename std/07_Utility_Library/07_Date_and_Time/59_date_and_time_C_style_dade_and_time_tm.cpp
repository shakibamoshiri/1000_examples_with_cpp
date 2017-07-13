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
/// std::tm
//  struct tm {}
//
//  A structure holding a calender date and time broken down into its components.
//
//  int tm_sec      seconds after the minutes
//  int tm_min      minutes after the hours
//  int tm_hour     hours since midnight
//  int tm_mday     day of the month
//  int tm_mon      month since January
//  int tm_year     year since 1900
//  int tm_wday     days since Sunday
//  int tm_yday     days since January
//  int tm_isdst    Daylight Saving Time flag
//
// NOTE: range allows for positive leap second.
//       Two leap seconds int the same minutes are not allowed



#include <iostream>
#include <ctime>
#include <iomanip>  // std::put_time

int main (){

    std::time_t time = std::time( nullptr );    // a raw time since epoch

    std::tm tm = *std::localtime( &time );         // matches the time to the structure tm

    tm.tm_min += 1;     // 1 minute later
    tm.tm_hour += 1;    // 1 hour later

    std::cout << std::ctime( &time );
    std::cout << std::put_time( &tm, "%c %Z" );
}


/* output for me:

Sat Dec 17 13:12:02 2016                13 : 12
Sat Dec 17 14:13:02 2016 IRST           14 : 13

*/






