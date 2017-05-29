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



int main(){

    const std::string string( "how are you today? I am fine, how about you!" );

    std::string::const_iterator first_questoin_mark = std::find( begin( string ), end( string ), 'I' );

    std::string found_string( first_questoin_mark, string.end() );
    std::cout << found_string << '\n';

}

/* output

I am fine, how about you!

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.

*/
