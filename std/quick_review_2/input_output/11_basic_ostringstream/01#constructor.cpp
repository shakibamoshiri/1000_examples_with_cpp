/*

A review of abstraction section from cplusplus.com

*/

/// basic_ostringstream constructor
//
//  Constructs a new object.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>  // std::stringbuf
#include <string>


int main(){

    std::ostringstream oss_1;
    std::ostringstream oss_2( std::ios_base::ate );

    oss_1.str( "How are you today?" );
    oss_2.str( "How are you today?" );

    oss_1 << " I am fine.";
    oss_2 << " I am fine.";

    std::cout << oss_1.str() << '\n';
    std::cout << oss_2.str() << '\n';

}
/**

 I am fine. today?
How are you today? I am fine.

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


**/
