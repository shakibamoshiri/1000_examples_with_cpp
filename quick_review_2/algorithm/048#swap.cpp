/*

A review of algorithm library

Modifying sequence operations

*/


#include <iostream>
#include <algorithm>
#include <vector>

/// swap
//  Exchanges values of two objects

int main(){

    std::vector< std::string > vec_1{ "one", "two", "three", "four" };
    std::vector< std::string > vec_2( vec_1.size() );

    std::swap( vec_2, vec_1 );

    std::cout << vec_1[ 0 ] << '\n';    //
    std::cout << vec_2[ 0 ] << '\n';    // one

}

/* output


*/
