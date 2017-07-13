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

    std::pair< int, char > pair( 10, 'A' );

    std::tuple< int, char > tuple = pair;
    print( tuple );


    // given Allocator my_alloc with a single-argument constructor my_alloc( int )
    // use my_alloc( 1 ) to allocate 10 ints in a vector
    std::vector< int, my_alloc > vector_1( 10, 1, my_alloc( 1 ) );

    // use my_alloc( 2 ) to allocate 10 ints in a vector in a tuple
    std::tuple< int, std::vector< int, my_alloc>, double> tuple_2
    ( std::allocator_arg, my_alloc( 2 ), 23, vector_1, -23.3 );

}

/* output for me


*/
