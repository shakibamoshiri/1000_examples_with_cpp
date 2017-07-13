/*

A review of abstraction section from cplusplus.com

*/

/// manipulator :: internal
//  ios_base& internal( ios_base& str )
//
//  Adjust field by inserting character at internal position.

#include <iostream>

int main(){

    short integer = -33;

    std::cout.width( 10 );
    std::cout << std::internal << integer << '\n';

    std::cout.width( 10 );
    std::cout << std::right << integer << '\n';

    std::cout.width( 10 );
    std::cout << std::left << integer << '\n';





}
/**
-       33
       -33
-33

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



**/
