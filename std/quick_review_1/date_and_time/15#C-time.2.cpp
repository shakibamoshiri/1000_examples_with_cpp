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
/// 02. data and time ( c ) in header <ctime>

//  time

#include <iostream>
//#include <chrono>
#include <ctime>
#include <iomanip>


int main(){

    std::time_t time = std::time( nullptr );
    std::tm my_time = *std::localtime( &time );
    std::cout << std::put_time( &my_time, "%c %Z" ) << '\n';

    my_time.tm_hour -= 1;   // 1 hour ago
    std::cout << std::put_time( &my_time, "%c %Z" ) << '\n';



}


/* output:

Mon Jan 30 16:55:50 2017 IRST
Mon Jan 30 15:55:50 2017 IRST

*/
/*
struct tm
{
  int tm_sec;			 Seconds.	[0-60] (1 leap second) *
  int tm_min;			 Minutes.	[0-59] *
  int tm_hour;			 Hours.	[0-23] *
  int tm_mday;			 Day.		[1-31] *
  int tm_mon;			 Month.	[0-11] *
  int tm_year;			 Year	- 1900.  *
  int tm_wday;			 Day of week.	[0-6]
  int tm_yday;			 Days in year.[0-365]
  int tm_isdst;			 DST.		[-1/0/1]


  long int tm_gmtoff;		 Seconds east of UTC.
  const char *tm_zone;		 Timezone abbreviation.

  long int __tm_gmtoff;		 Seconds east of UTC.
  const char *__tm_zone;	 Timezone abbreviation.

};
*/
