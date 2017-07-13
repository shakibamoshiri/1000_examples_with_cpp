/*

A review of string library( char_treats )

*/

/// char_traits::eq_int_type;
//  static constexpr bool eq_int_type( int_type x, int_type y ) noexcept;
//
//  Compares int_type value.


#include <iostream>
#include <string>

int main(){
    int array[ 4 ] = { 1,2,3,4 };
    int* ptr_to_array = array;

    for( const int i : { 1,2,3,4 } ){
        std::cout << std::char_traits< char >::eq_int_type( i, *ptr_to_array++ ) << '\n';
    }

}

/**

1
1
1
1

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


**/
