/*

A review of abstraction section from cplusplus.com

*/

/// basic_streambuf::sungetc
//  int_type sungetc()
//
//  Decrease current position



#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <sstream>




int main(){

    // sungetc()
    std::istringstream iss( "abcdefg" );

    std::cout << (char) iss.get();  // extracts one character: a

    iss.unget();                    // equivalent to streambuf -> sungetc
    std::cout << (char) iss.get();  // extracts one character: a again
    iss.unget();                    // equivalent to streambuf -> sungetc
    std::cout << (char) iss.get();  // extracts one character: a again
    iss.unget();                    // equivalent to streambuf -> sungetc
    std::cout << (char) iss.get();  // extracts one character: a again

}
/**

aaaa

**/
