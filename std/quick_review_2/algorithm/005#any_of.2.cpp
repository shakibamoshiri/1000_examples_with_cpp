/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <array>

/// any_of ( or at least one true condition )
//  template< class InputIterator, class UnaryPredicate >
//  bool any_of( InputIterator first, InputIterator last, UnaryPredicate function )
//
//  Test if any elements in range fulfills condition


int main(){

    std::array< int, 5 > array = { 1,2,0,4,5 }; // one zero is here

    bool find_any_zero = std::any_of( std::begin( array ), std::end( array ),
                                      []( const int integer ){ return integer == 0; } );
    if( find_any_zero ){
        puts( "there is at least one zero in the range" );
    } else {
        puts( "okay the list has no zero in it" );
    }

}

/* output

there is at least one zero in the range

Process returned 0 (0x0)   execution time : 0.008 s
Press ENTER to continue.




*/
