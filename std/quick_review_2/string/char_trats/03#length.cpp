/*

A review of string library( char_treats )

*/

/// char_traits::length
//  static size_t length( const char_type* str )
//
//  Gets the length of null-terminate string.

#include <iostream>
#include <string>
#include <cctype>        // tolower or toupper



int main(){

    std::cout <<  std::char_traits< char >::length( "how are you today?"); // 18

}
/**



**/
