/*

A review of string library( char_treats )

*/

/// char_traits::eq
//  static constexpr bool eq( char_type c, char_type d ) noexcept;
//
//  Compares characters for equality.

#include <iostream>
#include <string>
#include <cctype>        // tolower or toupper

struct custom_traits : std::char_traits< char > {
    static bool eq( char a, char b ){
        return tolower( a ) == tolower( b );
    }

    static const char* find( const char* str, std::size_t n, char c ){
        while( n-- && !( eq( *str, c ) ) ) ++str;

        return str;
    }
};

int main(){

    std::basic_string< char, custom_traits > string( "how are YOU today?" );
    std::cout << "looking for 't' may at position: " << string.find( 'y' ) << '\n';

}
/**

looking for 't' may at position: 8

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.

**/
