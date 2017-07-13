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

/// std::chrono::duration



#include <iostream>
#include <chrono>
#include <ctime>

int main(){

    using namespace std::chrono;

    system_clock::duration du( 1 );     // by default = second
    std::cout << du.count() << '\n';    // 1 seconds

    system_clock::duration du2( duration< int, std::ratio< 60 > >(3) );   // by default = second
    std::cout << du2.count() << '\n';     // 180 second == 3 minutes

}

/* output


1
180000000000

Process returned 0 (0x0)   execution time : 0.010 s
Press ENTER to continue.
*/
