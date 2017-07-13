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

/// std::chrono::duration::operator ++, -- , and so on.
//
//
///  member:
//  constructor, destructor, count
//  zero, min, max
//  operator overloading like, ==, !=, an so on.

#include <iostream>
#include <chrono>


int main(){

    typedef std::chrono::duration< int > second_t;  // equivalents to std::chrono::seconds

    second_t one_second( 1 );   // 1
    ++one_second;               // 2
    one_second += second_t( 58 );           // 60 == 1 minutes

    if( one_second.count() == 60 )
        std::cout << one_second.count() << '\n';




}

/* output


60

Process returned 0 (0x0)   execution time : 0.012 s
Press ENTER to continue.


*/
