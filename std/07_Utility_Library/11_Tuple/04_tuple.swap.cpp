/*
        std::tuple
        **********

defined in header <tuple>

Class template std::tuple is a fixed-size collection of heterogeneous
values. It is a generalization on std::pair.

Template Parameter:
    Type...                     the type of elements that the tuple is stored. Empty list is supported.

Member Function:
    constructor                 constructs a new tuple
    operator =                  assigns the contents of one tuple to another
    swap                        swaps the contents of two tuples



*/
/// std::tuple swap

//  Calls swap (which might be std::swap, or might be found via ADL)
//  for each element in *this and its corresponding element in order.

#include <iostream>
#include <tuple>

#include <string>




int main(){

    std::tuple< int, std::string, float > tuple_1, tuple_2;

    tuple_1 = std::make_tuple( 10, "this is the tuple_1", 3.2 );

    tuple_2.swap( tuple_1 );

    std::cout << "the content of tuple_2:\t"
              << std::get< 0 >( tuple_2 ) << ' '
              << std::get< 1 >( tuple_2 ) << ' '
              << std::get< 2 >( tuple_2 ) << '\n';


}

/* output for me


*/
