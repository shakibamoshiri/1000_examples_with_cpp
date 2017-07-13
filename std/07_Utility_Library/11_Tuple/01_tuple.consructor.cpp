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
/// std::tuple constructor
//  Constructs a new tuple

#include <iostream>
#include <tuple>

#include <string>
#include <vector>
#include <memory>


// helper function to print a tuple of any size
template< class Tuple, std::size_t N >
struct TuplePrinter {

    static void print( const Tuple& element ){
        TuplePrinter< Tuple, N - 1 >::print( element );
        std::cout << ", " << std::get< N - 1 >( element );
    }
};
// and
template< class Tuple > // partial specialization, omitted the std::size_t N
struct TuplePrinter< Tuple, 1 > {

    static void print( const Tuple& element ){
        std::cout << std::get< 0 >( element );   // there is only one element
    }
};
// and
template< class... ARGS >
void print( const std::tuple< ARGS... >& tuple_object ){

    TuplePrinter< decltype( tuple_object ), sizeof...( ARGS ) >::print( tuple_object );

}
// the end of helper function


int main(){

    std::tuple< int, std::string, double > tuple_1;
    std::cout << "(tuple_1) value-initialized:\t";
    print( tuple_1 );

    std::tuple< int, std::string, double > tuple_2( 23, "this is a tuple element", -34.34 );
    std::cout << '\n'
              << "(tuple_2) initialized with values:\t";
    print( tuple_2 );

    std::tuple< char, std::string, int > tuple_3( tuple_2 );    // copy-constructor
    std::cout << '\n'
              << "(tuple_3) implicit converted:\t";
    print( tuple_3 );

    std::tuple< int, double > tuple_4( std::make_pair( 2, 3.3 ) );
    std::cout << '\n'
              << "(tuple_4) constructed from a pair";
    print( tuple_4 );

}

/* output for me

(tuple_1) value-initialized:    0, , 0
(tuple_2) initialized with values:      23, this is a tuple element, -34.34
(tuple_3) implicit converted:   , this is a tuple element, -34
(tuple_4) constructed from a pair2, 3.3

*/
