/*
        std::tuple
        **********

defined in header <tuple>

Class template std::tuple is a fixed-size collection of heterogeneous
values. It is a generalization on std::pair.

Non-member Function:
    make_tuple                  creates a tuple object of the type defined by the argument types
    tie                         creates a tuple of l-value reference or unpacks a tuple
    forward_as_tuple            creates a tuple of r-value reference
    tuple_cat                   creates a tuple by concatenating any number of tuples
    std::get( std::tuple )      tuple accesses specified element
    operator ==                 lexicographically compares the value of tuples
    operator !=                 "
    operator >                  "
    operator <                  "
    operator <=                 "
    operator >=                 "
    std::swap ( std::tuple )    specializes the std::swap algorithm



*/
/// std::get

//  Extracts the elements from a tuple,
//  based on index (number) or type



#include <iostream>
#include <tuple>
#include <string>


// helper function to print a tuple of any size
template< class Tuple, std::size_t Size >
struct TuplePrinter {

    static void print( const Tuple& element ){

        TuplePrinter< Tuple, Size - 1 >::print( element );
        std::cout << ", " << std::get< Size - 1 >( element );

    }
};
// and specialization for only one element
template< class Tuple >
struct TuplePrinter< Tuple, 1 > {

    static void print( Tuple& element ){

        std::cout << std::get< 0 >( element );  // there is only one element
    }
};
// and main print function:
template< class... ARGS >
void print( const std::tuple< ARGS... > object ){

    TuplePrinter< decltype( object ), sizeof...( ARGS ) >::print( object );

}


int main(){

    std::string str( "tuple" );
    auto tuple = std::make_tuple( 2, 'c', str );

    // index-based access
    std::cout << std::get< 0 >( tuple ) << ' '
              << std::get< 1 >( tuple ) << ' '
              << std::get< 2 >( tuple ) << '\n';

    // type-based access
    std::cout << std::get< int >( tuple ) << ' '
              << std::get< char >( tuple ) << ' '
              << std::get< std::string >( tuple ) << '\n';

}

/* output for me


*/
