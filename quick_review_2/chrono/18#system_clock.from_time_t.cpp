/*

A review of chrono library

chrono is the name of a header, but also of a sub-namespace:
All the element in this header, ( except for the comment_type specialization )
are not defined directly under the std namespace ( like most of the standard library )
but under the std::chrono namespace.

The mainly concepts:
    duration
    time point
    clock
        system_clock
        steady_clock
        high_resolution_clock

    traits:
        trait_as_floating_point
        duration_value
        common_type( duration )

    function:
        duration_cast<>()
        time_point_cast<>()

hours           signed integral type of at least 23 bits ratio<3600,1>
minutes         signed integral type of at least 29 bits ratio<60,1>
seconds         signed integral type of at least 35 bits ratio<1,1>
milliseconds    signed integral type of at least 45 bits ratio<1,1000>
microseconds    signed integral type of at least 55 bits ratio<1,1000000>
nanoseconds     signed integral type of at least 64 bits ratio<1,1000000000>
*/

/// std::chrono::system_clock.from_time_t
//  time_point
//
/// member:
//  now, from_time_t, to_time_t

#include <iostream>
#include <chrono>
#include <ctime>

int main(){
    using namespace std::chrono;

    std::tm time_info = std::tm();

    time_info.tm_year = 100;        // year: 2000
    time_info.tm_mon = 0;         // month: January
    time_info.tm_mday = 1;          // first

    std::time_t tt = std::mktime( &time_info );
    std::cout << std::ctime( &tt ) << '\n';

    system_clock::time_point tp = system_clock::from_time_t( tt );
    system_clock::duration du   = system_clock::now() - tp;

    // convert the date to number of days
    typedef duration< int, std::ratio< 60 * 60 * 24 > > one_day_t;
    one_day_t n_day = duration_cast< one_day_t >( du );
    std::cout << du.count() << '\n';
    std::cout << n_day.count() << '\n';
}

/* output
Sat Jan  1 00:00:00 2000

545147446173738232
6309

Process returned 0 (0x0)   execution time : 0.052 s
Press ENTER to continue.


*/
