/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <array>

/// any_of ( or at least one true condition )
//  template< class InputIterator, class UnaryPredicate >
//  bool none_of( InputIterator first, InputIterator last, UnaryPredicate function )
//
//  Test if no elements fulfill condition.


int main(){

    const std::array< short, 5 > array = { 2,4,5,8,10 };

    const bool find_none_odd = std::none_of( std::begin( array ), std::end( array ),
                                             []( const short integer ){ return integer % 2; } );    // integer % 2 return 0 for all even numbers.

    // if none of the element were even so
    if( find_none_odd ){
        puts( "all element in the array are even" );
    } else {
        puts( "there are some odd number in the array" );
    }

}

/* output

there are some odd number in the array

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.





*/
