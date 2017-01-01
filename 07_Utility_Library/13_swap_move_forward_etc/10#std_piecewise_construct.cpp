/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::piecewise_construct

//  defined in header <utility>

//  constexpr std::piecewise_construct_t piecewise_construct = std::piecewise_construct_t();
//  it is an instance of empty struct tag type std::piecewise_construct_t



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

    std::pair< S, S > p2( std::piecewise_construct, t1, t1 );

}
/* output for me:



*/
