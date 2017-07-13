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
/// std::wcsftime
//  std::size_t wcsftime (wchar_t* str, std::size_t count, const wchar_t* format, const std::tm* time)
//
//  Converts the date and time information from a given calender time time
//  to a null-terminated wide character string for according to format
//  string format. Up to count bytes are written.
//
//  for more detail see the main webpage.


#include <iostream>
#include <ctime>
#include <locale>

int main (){

    std::locale::global( std::locale("fa_IR.utf8") );
    std::time_t time = std::time( nullptr );

    wchar_t wstr[100];
    if( std::wcsftime( wstr, sizeof( wstr ), L"%A %c", std::localtime( &time )) )
        std::cout << wstr << std::endl;

}


/* output for me:

0xbfb6e36c

*//* why? I dot not know! */


