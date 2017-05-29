/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

/// swap_range
//  Exchanges values of two objects

int main(){

    std::vector< std::string > vec_1{ "one", "two", "three", "four" };
    std::vector< std::string > vec_2( vec_1.size() );

    std::swap_ranges( vec_1.begin() + 1, vec_1.end() - 1, // to
                      vec_2.begin() + 1 );

    for( const std::string& str : vec_1 ){
        std::cout << std::quoted( str ) << '\n';
    }

    puts( "========== [after swap_range] ===========" );

    for( const std::string& str : vec_2 ){
        std::cout << std::quoted( str ) << '\n';
    }


}

/* output
"one"
""
""
"four"
========== [after swap_range] ===========
""
"two"
"three"
""

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.

*/
