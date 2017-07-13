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

//  duration

#include <iostream>
#include <chrono>


int main(){

    std::cout << std::chrono::hours( 1 ).count() << '\n'; // 1 hours is 1 tick
    std::chrono::hours one( 1 );
    std::cout << std::chrono::duration_cast< std::chrono::minutes >( one ).count() << '\n';         // 1 hour is 60 ticks
    std::cout << std::chrono::duration_cast< std::chrono::milliseconds >( one ).count() << '\n';    // 1 hour is 3600000 ticks
    std::cout << std::chrono::duration_cast< std::chrono::microseconds >( one ).count() << '\n';    // 1 hour is 3600000000 ticks
    std::cout << std::chrono::duration_cast< std::chrono::nanoseconds >( one ).count() << '\n';     // 1 hour is 3600000000000 ticks

}

/* output:

1
60
3600000
3600000000
3600000000000

*/
