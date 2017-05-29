/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <string>

/// for_each:
//  template< class InputIterator, class Function >
//  Function for_each ( InputIterator first, InputIterator last, Function function )
//
//  Applies function to range

const struct S {
    void operator()( const short integer ){
        putchar( integer );
    }

} func; // a single const object of structure S
int main(){

    const std::string string( "how are you today? I am fine, how about you!" );

    std::string::const_iterator first_questoin_mark = std::find( begin( string ), end( string ), '?' );

    std::for_each( first_questoin_mark, end( string ),
                   func );


}

/* output


? I am fine, how about you!
Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.



*/
