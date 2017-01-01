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
/// std::mktime
//  std::time_t mktime (std::tm* time)
//
//  Converts local calender time to a time since epoch as a time_t
//  object. time-tm_wday and time_tm->tm_yday are ignored. The values
//  in time are permitted to be outside their normal range.
//  A negative value of time-tm_isdst causes mktime to attempt to determine
//  if Daylight Saving Time was in effect.

#include <iostream>
#include <ctime>
#include <iomanip>  // std::put_time

int main (){

    std::time_t time = std::time ( nullptr );
    std::tm tm = *std::localtime ( &time );

    std::cout << "Today is:\t" << std::put_time( &tm, "%c %Z" ) << std::endl;

    tm.tm_mon = -100;

    std::mktime( &tm );

    std::cout << "100 months ago was: " << std::put_time( &tm, "%c %Z" ) << std::endl;

}


/* output for me:

Today is:       Sat Dec 17 12:57:25 2016 IRST
100 months ago was: Mon Sep 17 12:57:25 2007 IRST

*/






