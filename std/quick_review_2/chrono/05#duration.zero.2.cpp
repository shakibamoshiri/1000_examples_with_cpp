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

/// std::chrono::duration.zero()
//
//  duration value of zero.
//  The function calls duration_value::zero to obtain the zero value for its internal count object
///  member:
//  constructor, destructor, count
//  zero, min, max
//  operator overloading like, ==, !=, an so on.

#include <iostream>
#include <chrono>


int main(){

    using std::chrono::steady_clock;

    steady_clock::time_point begin = steady_clock::now();   // a time_point
    std::cout << "something for printing...\n";
    steady_clock::time_point end   = steady_clock::now();   // another time_point

    steady_clock::duration result = end - begin;

    if( result == steady_clock::duration::zero() ){
        std::cout << "the internal clock did not tick\n";
    } else {
        std::cout << "the internal clock advanced ( in seconds ): " << std::chrono::duration_cast< std::chrono::seconds >( result ).count()<< '\n';
        std::cout << "the internal clock advanced ( in milliseconds ): " << std::chrono::duration_cast< std::chrono::milliseconds >( result ).count()<< '\n';
        std::cout << "the internal clock advanced ( in microseconds ): " << std::chrono::duration_cast< std::chrono::microseconds >( result ).count()<< '\n';
        std::cout << "the internal clock advanced ( in nanoseconds ): " << std::chrono::duration_cast< std::chrono::nanoseconds >( result ).count()<< '\n';
        std::cout << "the internal clock advanced ( in original ): " << result.count() << '\n';
    }




}

/* output

something for printing...
the internal clock advanced ( in seconds ): 0
the internal clock advanced ( in milliseconds ): 0
the internal clock advanced ( in microseconds ): 482
the internal clock advanced ( in nanoseconds ): 482276
the internal clock advanced ( in original ): 482276

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.




*/
