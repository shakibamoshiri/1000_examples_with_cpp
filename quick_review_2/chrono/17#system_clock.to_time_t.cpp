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

/// std::chrono::system_clock.to_time_t
//  time_point
//
/// member:
//  now, from_time_t, to_time_t

#include <iostream>
#include <chrono>
#include <ctime>

int main(){
    using namespace std::chrono;

    duration< int, std::ratio< 60 * 60 * 24 > > one_day( 1 );

    system_clock::time_point today    = system_clock::now();
    system_clock::time_point tomorrow = today + one_day;

    std::time_t tt = system_clock::to_time_t( today );
    std::cout << ctime( &tt ) << '\n';
    puts( "-------------" );
    tt = system_clock::to_time_t( tomorrow );
    std::cout << ctime( &tt ) << '\n';



}

/* output

Mon Apr 10 14:39:17 2017

-------------
Tue Apr 11 14:39:17 2017


Process returned 0 (0x0)   execution time : 0.040 s
Press ENTER to continue.
*/
