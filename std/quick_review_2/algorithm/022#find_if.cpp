/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <array>

/// find_if
//  template< class InputIterator, class UnaryPredicate >
//  InputIterator find_if( InputIterator first, InputIterator last, UnaryPredicate pre )
//
//  Finds a value in a range if would be found.



int main(){

    std::array< int, 7 > array { 1,3,5,6,7,9,11 };
    std::array< int, 0 >::const_iterator it_find_if = std::find_if( array.begin(), array.end(),
                                                                    []( const int integer ){ return integer % 2 == 0; } );
    std::cout << "first even number in the array is: "
              << *it_find_if << '\n';

}

/* output


first even number in the array is: 6

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



*/
