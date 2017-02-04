

#include <iostream>
//#include <utility>  // pair
#include <tuple>    // tie


int main(){

    std::tuple< int, char, float > tuple( 1, 'A', 1.1 );
    std::cout << std::get< 0 >( tuple ) << ' '
              << std::get< 1 >( tuple ) << ' '
              << std::get< 2 >( tuple ) << '\n';



}
