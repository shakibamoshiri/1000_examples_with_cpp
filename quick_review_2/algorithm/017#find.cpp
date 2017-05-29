/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <string>

/// find
//  template< class InputIterator, class T>
//  InputIterator find( InputIterator first, InputIterator last, const T& value )
//
//  Finds a value in a range.

const struct S {
    void operator()( const short integer ){
        putchar( integer );
    }

} func; // a single const object of structure S
int main(){

    const std::string string( "how are you today? I am fine, how about you!" );

    // std::string::const_iterator first_questoin_mark = std::find( begin( string ), end( string ), '?' );

    // Also we can uses the find directly
    std::for_each( std::find( begin( string ), end( string ), '?' ),    // first iterator
                   end( string ),                                       // second iterator
                   func );                                              // apply function

}

/* output




*/
