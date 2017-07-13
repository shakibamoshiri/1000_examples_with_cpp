/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

/// move
//  Move range of element

int main(){

    std::vector< std::string > vec_1{ "one", "two", "three", "four" };
    std::vector< std::string > vec_2( vec_1.size() );

    std::move( begin( vec_1 ), end( vec_1 ),
               begin( vec_2 ) );

    for( const std::string& str : vec_1 )
        std::cout << std::quoted( str ) << '\n';

    puts( "---------------" );

    for( const std::string& str : vec_2 )
        std::cout << std::quoted( str ) << '\n';

}

/* output
""
""
""
""
---------------
"one"
"two"
"three"
"four"

Process returned 0 (0x0)   execution time : 0.011 s
Press ENTER to continue.



*/
