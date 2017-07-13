/*

A review of string library( char_treats )

*/

/// char_traits::to_int_type
//  static constexpr int_type to_int_type( char_type c ) noexcept;
//
//  to int type


#include <iostream>
#include <string>
#include <fstream>



int main(){

    for( const char c : "1234" ){
        std::cout << std::char_traits< char >::to_int_type( c ) << ' ';
    }

}

/**

49 50 51 52 0
Process returned 0 (0x0)   execution time : 0.004 s
Press ENTER to continue.



**/
