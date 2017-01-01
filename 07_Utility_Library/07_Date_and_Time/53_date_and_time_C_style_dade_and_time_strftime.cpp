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
/// std::strftime
//  std::size_t strgtime (char* str, std::size_t count, const char* format, const std::tm* time)
//
//  Converts the date and time information from a given calender time time
//  to a null-terminated multibyte character string for according to format
//  string format. Up to count bytes are written.
//
//  for more detail see the main webpage.


#include <iostream>
#include <ctime>
#include <locale>

int main (){

    std::locale::global( std::locale("fa_IR.utf8") );   // for me
    // std::locale::global( std::locale("en_US.utf8") );   // may be for you
    // std::locale::global( std::locale("ja_JP.utf8") );   // may be for you
    std::time_t time = std::time( nullptr );

    char mbstr[100];
    if( std::strftime( mbstr, sizeof( mbstr ), "%A %c", std::localtime( &time )) )
        std::cout << mbstr << std::endl;

}


/* output for me:

www mmm dd mm:mm:ss yyyy
Sat Dec 17 12:00:22 2016


*/


