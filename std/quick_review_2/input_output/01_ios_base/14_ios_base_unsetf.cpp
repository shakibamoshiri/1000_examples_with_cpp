/*

A review of abstraction section from cplusplus.com

*/

/// ios_base::setf
//  fmtflag setf( ftmflag fmt )                 // set
//  fmtflag setf( fmtflag fmt, fmtflag mask )   // mask
//
//  Sets specific format flags.

//  format flag value:
//  left, right, internal, doc, hex, oct, fixed, scientific

//  format filed bitmask
//  adjustfield, basefield, floatfield



#include <iostream> // std::cout, std::ios

int main(){
    // modifying flags with setf / unsetf

    std::cout.setf( std::ios::hex, std::ios::basefield ); // set hex as a base field
    std::cout.setf( std::ios::showbase );                   // activate showbase
    std::cout << 100 << '\n';

    std::cout.unsetf( std::ios::showbase );                 // deactivate showbase
    std::cout << 100 << '\n';


}
/**


0x64
64

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.


**/
