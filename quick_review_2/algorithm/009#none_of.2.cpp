/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

/// any_of ( or at least one true condition )
//  template< class InputIterator, class UnaryPredicate >
//  bool none_of( InputIterator first, InputIterator last, UnaryPredicate function )
//
//  Test if no elements fulfill condition.


int main(){

    const std::string string( "looking for a uppercase latter but there is no ones" );

    const bool find_any_uppercase = std::none_of( string.begin(), string.end(),
                                            []( const char chr ){ return chr == std::toupper( chr ) && chr != ' '; } );
    if( find_any_uppercase ){
        puts( "string has not uppercase letters" );
    } else {
        puts( "string has at least one uppercase letter" );
    }

}

/* output

string has not uppercase letters

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.




*/
