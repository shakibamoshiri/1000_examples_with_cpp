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
/// std::ctime
//  char* ctime (const std::time_t time)
//
//  Converts given time since epoch to a calender local time and then
//  to a textual representation, as if by calling std::actime(std::localtime(time)).
//  The result string has the following format:
//  Www:    the day of the week
//  Mmm:    the  month
//  dd:     the day of the month
//  hh:     hours
//  mm:     minutes
//  ss:     seconds
//  yyyy:   years
//
//  The function does not support localization


#include <iostream>
#include <ctime>

int main (){

    std::time_t result = std::time( nullptr );
    std::cout << "www mmm dd mm:mm:ss yyyy\n";
    std::cout << std::ctime ( &result );

}


/* output for me:

www mmm dd mm:mm:ss yyyy
Sat Dec 17 12:00:22 2016


*/


