/*

A review of algorithm library

*/


#include <iostream>
#include <algorithm>
#include <array>

/// for_each:
//  template< class InputIterator, class Function >
//  Function for_each ( InputIterator first, InputIterator last, Function function )
//
//  Applies function to range

void function( const int integer ){
    std::cout << integer << '\n';
}

int main(){

    const std::array< short, 5 > array = { 2,4,5,8,10 };

    std::for_each( array.begin(), array.end(),
                   function );
              // applies that function for all elements

}

/* output

2
4
5
8
10

Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.




*/
