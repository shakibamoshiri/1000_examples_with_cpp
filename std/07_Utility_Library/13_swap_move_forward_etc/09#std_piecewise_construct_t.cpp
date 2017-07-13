/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::piecewise_construct_t

//  defined in header <utility>

//  std::piecewise_construct_t is an empty tag type used to disambiguate
//  between different functions that take two tuple argument.



#include <iostream>
#include <utility>
#include <tuple>

struct S {
    S( std::tuple< int, float > )
    { std::cout << "constructed a S from a tuple\n"; }

    S( int, float )
    { std::cout << "constructed a S form an int and a float\n"; }
};



int main(){

    std::tuple< int, float > t1( 2, 4.3 );
    std::pair< S, S > p1( t1, t1 );
    // constructed a S from a tuple
    // constructed a S from a tuple

    std::pair< S, S > p2( std::piecewise_construct, t1, t1 );
    // constructed a S form an int and a float
    // constructed a S form an int and a float
}
/* output for me:
constructed a S from a tuple
constructed a S from a tuple
constructed a S form an int and a float
constructed a S form an int and a float


*/
