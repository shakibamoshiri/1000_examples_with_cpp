/*

A review of string library( char_treats )

*/

/// char_traits::find
//  static const char_type* find( const char_type* p, const char_type* q, const char_type& c );
//
//  Finds first occurrence of character c;

#include <iostream>
#include <string>
#include <cctype>        // tolower or toupper


int main(){
    const char how[] = "how are you today?";
    const char* result = std::char_traits< char >::find( how, std::char_traits< char >::length( how ), 't' );   // looking for 't'
    if( result ){
        std::cout << "the first 't' is at position: " << ( result - how ) << '\n';
    }
}

/**



**/
