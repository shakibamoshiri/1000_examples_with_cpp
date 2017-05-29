

#include <iostream>
#include <utility>  // pair
#include <tuple>    // tie

template< typename A, typename B >
std::pair< A, B > func( A first, B second ){
    puts( "call func" );
    return { first, second };
}

int main(){

    auto pair = func( 'f', 's' );
    std::cout << pair.first << ' ' << pair.second << '\n';

    std::pair< int, int > p1 = func( 1, 3 );
    std::cout << p1.first << ' ' << p1.second << '\n';





}
