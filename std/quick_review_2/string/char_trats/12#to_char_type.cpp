/*

A review of string library( char_treats )

*/

/// char_traits::to_char_type
//  static constexpr char_type to_char_type( int_type c ) noexcept;
//
//  to char type


#include <iostream>
#include <string>
#include <fstream>



int main(){

    for( const int i : "1234" ){
        std::cout << std::char_traits< char >::to_char_type( i );
//        std::cout << i;
    }

}

/**

1234
Process returned 0 (0x0)   execution time : 0.010 s
Press ENTER to continue.

**/
