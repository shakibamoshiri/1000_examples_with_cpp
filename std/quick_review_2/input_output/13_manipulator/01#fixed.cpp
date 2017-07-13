/*

A review of abstraction section from cplusplus.com

*/

/// manipulator
//  ios_base& fixed( ios_base& str )
//
//  Uses fixed floating-point notation.

#include <iostream>

int main(){

    double d = 23.4323;

    std::cout.precision( 14 );
    std::cout << d << '\n';

    std::cout << std::fixed << d << '\n';

}
/**

23.4323
23.43230000000000

Process returned 0 (0x0)   execution time : 0.005 s
Press ENTER to continue.


**/
