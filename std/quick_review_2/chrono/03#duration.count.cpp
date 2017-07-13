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

/// std::chrono::duration.count()
//  Get count
//  representation value of the duration count.
//
///  member:
//  constructor, destructor, count
//  zero, min, max
//  operator overloading like, ==, !=, an so on.

#include <iostream>
#include <chrono>


int main(){

    std::chrono::milliseconds one_second( 1000 );
    one_second *= 60;       // == one minute

    std::cout << one_second.count() << '\n';    // 60,000 milliseconds
    std::cout << ( one_second.count() * std::chrono::milliseconds::period::num ) / std::chrono::milliseconds::period::den << '\n';
    //                60000           *       1                                  /     1000

}

/* output

60000
60

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.




*/
