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

//  time_point

#include <iostream>
#include <chrono>
#include <ctime>


int main(){

    typedef std::chrono::time_point< std::chrono::_V2::system_clock, std::chrono::nanoseconds > time_point;
    time_point now = std::chrono::_V2::system_clock::now(); // 1485780880575819849
    std::cout << now.time_since_epoch().count() << '\n';
    std::cout << std::chrono::duration_cast< std::chrono::seconds >(now.time_since_epoch()).count() << '\n';    // 1485780880

    std::time_t time = std::time( nullptr );    // 1485780880
    std::cout << time << '\n';

}


/* output:

1485780880575819849
1485780880
1485780880

*/
