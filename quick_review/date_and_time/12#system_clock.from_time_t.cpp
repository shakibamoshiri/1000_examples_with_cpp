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
/// 02. data and time ( c++ ) in header <chrono>

//  clock
//      system_clock            -> wall clock
//          now
//          to_time_t
//          form_time_t
//
//      stead_clock             -> monotonic clock
//          now
//
//      high_resolution_clock   -> the shortest tick period of time
//          now

#include <iostream>
#include <chrono>
#include <ctime>


int main(){

    typedef std::chrono::_V2::system_clock system_clock;
    typedef std::chrono::time_point< system_clock, std::chrono::nanoseconds > wall_clock;

    std::time_t now_time = std::time( nullptr );
    std::cout << now_time << '\n';

    // convert now_time to system_clock
    // it has a member function named from_time_t
    // also you can yourself converted directly
    typedef std::chrono::time_point<system_clock, std::chrono::seconds> from_time_t;

    wall_clock s_c_t = std::chrono::time_point_cast< system_clock::duration >( from_time_t( std::chrono::seconds( now_time ) ) );

    std::cout << s_c_t.time_since_epoch().count() << '\n';



}


/* output:

1485780292
1485780292000000000

*/
