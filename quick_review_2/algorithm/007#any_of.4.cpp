/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

/// any_of ( or at least one true condition )
//  template< class InputIterator, class UnaryPredicate >
//  bool any_of( InputIterator first, InputIterator last, UnaryPredicate function )
//
//  Test if any elements in range fulfills condition


int main(){

    const std::string string( "looking for a uppercase latter but there is no ones" );

    const bool find_any_uppercase = std::any_of( string.begin(), string.end(),
                                            []( const char chr ){ return chr != std::tolower( chr ); } );
    if( find_any_uppercase ){
        puts( "string has at least one uppercase letter" );
    } else {
        puts( "string has not uppercase letters" );
    }

}

/* output

string has not uppercase letters

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.





*/
