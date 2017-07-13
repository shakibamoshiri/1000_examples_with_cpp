/*

A review of abstraction section from cplusplus.com

*/

/// basic_istringstream constructor

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>  // std::stringbuf
#include <string>
#include <algorithm>



int main(){

    std::string string_value( "3 -3 55 243 99 0 1" );
    std::istringstream iss( string_value );

    int value = 0;
    for( short index = 0; index <= std::count( string_value.begin(), string_value.end(), ' ' ); ++index ){
        iss >> value;
        std::cout << "value: " << value << '\n';
    }


}
/**

value: 3
value: -3
value: 55
value: 243
value: 99
value: 0
value: 1

Process returned 0 (0x0)   execution time : 0.005 s
Press ENTER to continue.

**/
