/*

A review of string library( char_treats )

*/

/// char_traits::compare
//  static int compare( const char_type* p, const char_type* q, size_t n );
//
//  Compares sequence of characters.

// The function performs a lexicographical comparison where two characters are considered equal if
// member eq returns true, and one character is considered less than another one if member lt returns
// true.


// Return Value
// Returns a signed integral indicating the relation between the sequences:
// 0 All characters compare equal
// <0 The first character that does not compare equal is less in p.
// >0 The first character that does not compare equal is greater in p.


#include <iostream>
#include <string>
#include <cctype>        // tolower or toupper

// case-insensitive traits
struct custom_traits : std::char_traits< char > {
    static bool eq( char a, char b ){
        return tolower( a ) == tolower( b );
    }

    static bool lt( char a, char b ){
        return tolower( a ) < tolower( b );
    }

    static int compare( const char* str_1, const char* str_2, std::size_t n ){
        while( n-- ){

            if( !eq( *str_1, *str_2 ) ){
                return lt( *str_1, *str_2 ) ? -1 : 1;
            }

            ++str_1;
            ++str_2;
        }
        return 0;
    }
};


int main(){

    std::basic_string< char, custom_traits > one( "one" ), ONE( "ONE" );
    if( one == ONE )
        std::cout << "both are equal\n";
    else
        std::cout << "Not equal\n";
}
/**

both are equal

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



**/
