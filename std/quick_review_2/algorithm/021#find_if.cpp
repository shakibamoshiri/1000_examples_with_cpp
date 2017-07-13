/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <string>

/// find_if
//  template< class InputIterator, class UnaryPredicate >
//  InputIterator find_if( InputIterator first, InputIterator last, UnaryPredicate pre )
//
//  Finds a value in a range if would be found.



int main(){

    std::string string( "a b c d e F e d c b a" );

    // find the first Uppercase Letter
    std::string::const_iterator it_find = std::find_if( string.begin(), string.end(),
                                                        []( const char chr ){ return ( chr == std::toupper( chr ) && chr != ' ' ); } );

    // from that uppercase letter tu to the end
    std::string result( it_find, string.cend() );
    std::cout << result << '\n';

}

/* output

F e d c b a

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
