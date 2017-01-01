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
/// std::localtime
//  std::tm* localtime (std::time_t* time);
//
//  Converts given time since epoch as std::time_t value
//  into calender time, expressed in local time.


#include <iostream>
#include <ctime>
#include <iomanip>

int main (){

  std::time_t time = std::time( nullptr );

  std::cout << "UTC:\t" << std::put_time( std::gmtime( &time ), "%c %Z" ) << '\n';
  std::cout << "Local:\t" << std::put_time( std::localtime( &time ), "%c %Z" ) << '\n';

}


/* output for me:

UTC:    Sat Dec 17 09:00:15 2016 GMT
Local:  Sat Dec 17 12:30:15 2016 IRST

*/






