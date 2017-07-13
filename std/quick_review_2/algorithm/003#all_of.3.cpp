/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <array>

/// all_of
//  template< class InputIterator, class UnaryPredicate >
//  bool all_of( InputIterator first, InputIterator last, UnaryPredicate function )
//
//  Test condition on all element in range


int main(){

    const char c_array[] = "my name is shakib";  // in fact Shakib

    const bool result_is_true = std::all_of( std::begin( c_array ), std::end( c_array ),
                                             []( const char chr ){ return ( ( chr >= 'a'  &&  chr <= 'z' ) ||  chr == ' '  || chr == '\0' ); } ); // return integer % 2 == 1

    if( result_is_true ){
        puts( "all elements in c_array are lowercases" );
    } else {
        puts( "some of the element in c_array are uppercases" );
    }

}

/* output


all elements in c_array are lowercases

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



*/
