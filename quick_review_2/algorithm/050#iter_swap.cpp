/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

/// iter_swap
//  Exchanges values of two objects pointed by two iterators.

int main(){

    std::vector< std::string > vec_1{ "one", "two", "three", "four" };
    std::vector< std::string > vec_2( vec_1.size() );

    std::iter_swap( vec_2.end() - 1, vec_1.end() - 1 );

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
"two"
"three"
""
========== [after swap_range] ===========
""
""
""
"four"

Process returned 0 (0x0)   execution time : 0.013 s
Press ENTER to continue.

*/
