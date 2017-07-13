/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::fmtflags
// Type for stream format flags


#include <iostream> // std::cout, std::ios

int main(){
    // ios_base::fmtflags

    // using fmtflags as class member constants
    std::cout.setf( std::ios_base::hex, std::ios_base::basefield );
    std::cout.setf( std::ios_base::showbase );
    std::cout << 20 << '\n';

    // using fmtflags as inherited class member constants
    std::cout.setf( std::ios::hex, std::ios::basefield );
    std::cout.setf( std::ios::showbase );
    std::cout << 30 << '\n';


    // using fmtflags as object member constants
    std::cout.setf( std::cout.hex, std::cout.basefield );
    std::cout.setf( std::cout.showbase );
    std::cout << 40 << '\n';

    //
}
/**

0x14
0x1e
0x28

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



**/
