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
/// 02. data and time ( c ) in header <ctime>

//  time

#include <iostream>
//#include <chrono>
#include <ctime>


int main(){

    std::time_t time = std::time( nullptr );    // row time since epoch
    std::cout << std::asctime( std::localtime( &time ) ) << '\n';
    std::cout << std::asctime( std::gmtime( &time ) ) << '\n';

}


/* output:

Mon Jan 30 16:37:49 2017

Mon Jan 30 13:07:49 2017
*/
