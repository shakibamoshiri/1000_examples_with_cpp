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

    std::chrono::duration< double , std::ratio< 3600, 1 > > user_one_hour( 1 );
    std::cout << user_one_hour.count() << '\n';
    std::cout << std::chrono::duration_cast< std::chrono::minutes >( user_one_hour ).count() << '\n';
    std::cout << std::chrono::duration_cast< std::chrono::seconds >( user_one_hour ).count() << '\n';

}

/* output:

1
60
3600

*/
