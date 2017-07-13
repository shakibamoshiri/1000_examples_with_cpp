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

/// std::chrono::high_resolution_clock
//  high_resolution_clock is the clock with the shortest tick period. It may be a synonym for
//  system_clock or steady_clock.
//
/// member:
//  now

#include <iostream>
#include <chrono>
// #include <ctime>

int main(){
    using namespace std::chrono;

    std::cout << "printing 1000 asterisk:\n";

    high_resolution_clock::time_point begin = high_resolution_clock::now();
    for( short count = 0; count < 1000; ++count )
        putchar( '*' );
    high_resolution_clock::time_point end = high_resolution_clock::now();

    duration< double > time_span = duration_cast< duration< double > >( end - begin );
    std::cout << "\nprinting 1000 asterisk took: " << time_span.count() << "seconds";


}

/* output
printing 1000 asterisk:
****************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************
printing 1000 asterisk took: 4.023e-05seconds
Process returned 0 (0x0)   execution time : 0.017 s
Press ENTER to continue.

*/
