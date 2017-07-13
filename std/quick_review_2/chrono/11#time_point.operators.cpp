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

/// std::chrono::time_point
//  time_point object expresses a point in time relative to a clock's epoch.
/*
compound assignment
(member functions)
tp += dtn *this
tp -= dtn *this
tp + dtn a time_point value


arithmetic operators
(non-member functions) tp - dtn a time_point value
tp + dtn a time_point value
dtn + tp a time_point value
tp - tp2 a duration value
tp == tp2 a bool value
tp != tp2 a bool value

relational operators
(non-member functions) tp > tp2 a bool value
tp == tp2 a bool value
tp != tp2 a bool value
tp < tp2 a bool value
tp >= tp2 a bool value
tp <= tp2 a bool value

Where tp and tp2 are time_point objects, and dtn is a duration object.
*/
/// member:
//  constructor, destructor, time_since_epoch
//  min, max
//  operators ( ==, !=, ++, --, and so on )

#include <iostream>
#include <chrono>
#include <regex>

int main(){
    using namespace std::chrono;

    system_clock::time_point tp_1, tp_2;
    system_clock::duration du( 1s );    // 1 second

    tp_1 += du;
    tp_2 += duration< int >( 3 );       // 3 seconds

    std::cout << ( tp_1 == tp_2 ? "equal" : "not equal" ) << '\n';

}

/* output

not equal

Process returned 0 (0x0)   execution time : 0.047 s
Press ENTER to continue.

*/
