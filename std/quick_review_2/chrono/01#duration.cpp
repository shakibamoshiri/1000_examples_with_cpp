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
//  a duration object express a time span by means of a count and a period.
//  member:
//  constructor, destructor, count
//  zero, min, max
//  operator overloading like, ==, !=, an so on.

#include <iostream>
#include <chrono>


int main(){

    // some typedef
    typedef std::chrono::duration< int > second_t;      // by default std::ratio< 1, 1 >
    typedef std::chrono::duration< int, std::milli > milliseconds_t;
    typedef std::chrono::duration< int, std::ratio< 60 * 60 > > hour_t;

    hour_t one_day( 24 );           // equivalents to 24 hours
    second_t one_hour( 60 * 60 );   // 3600 seconds
    second_t one_day_in_second( one_day );

    std::cout << one_day.count() << '\n';
    std::cout << one_hour.count() << '\n';
    std::cout << one_day_in_second.count() << '\n';

}

/* output

24
3600
86400

Process returned 0 (0x0)   execution time : 0.027 s
Press ENTER to continue.



*/
