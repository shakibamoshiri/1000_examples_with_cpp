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
/// std::tuple operator =
//  Replaces the contents of the tuple with the contents
//  of another pair or tuple

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
    std::tuple< int, char > tuple;
    tuple = pair;       // copy-assignment operator
    print( tuple );

    std::cout << '\n';
    std::tuple< int, char > tuple_2;
    tuple_2 = std::move( tuple );   // move-assignment operator
    print( tuple_2 );


}

/* output for me


*/
