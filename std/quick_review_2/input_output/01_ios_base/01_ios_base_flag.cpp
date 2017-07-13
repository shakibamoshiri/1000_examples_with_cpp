/*

A review of abstraction section from cplusplus.com

*/
/// ios

#include <iostream>

int main(){
    // modify flag
    std::cout.flags( std::ios::right | std::ios::hex | std::ios::showbase );
    std::cout.width( 10 );
    std::cout << 100 << '\n';
}
/**

      0x64

Process returned 0 (0x0)   execution time : 0.005 s
Press ENTER to continue.

**/
