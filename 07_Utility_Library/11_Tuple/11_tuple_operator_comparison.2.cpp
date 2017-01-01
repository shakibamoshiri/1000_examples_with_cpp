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
/// operator comparison ==, !=, <, >, <=, >=

//  Compares every element of the tuple 'lhs' with the
//  corresponding element of the tuple 'rhs.
//  or
//  Compares 'lhs' and 'rhs' lexicographically, that is
//  compares the first elements, if they are equivalent
//  compares the second elements, if those are equivalent
//  compares the third elements, and so on.



#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>


int main(){

    std::vector< std::tuple< int, const char*, float > > vector;

    vector.emplace_back( 3, "three", 3.3 );
    vector.emplace_back( 2, "two", 2.2 );
    vector.emplace_back( -1, "-one", -1.2 );
    vector.emplace_back( 5, "five", 5.5 );
    vector.emplace_back( 0, "zero", 0.0 );

    // so the contents is sortable
    std::sort( vector.begin(), vector.end() );

    // auto temp == std::tuple< int, const char*, float >
    for( auto temp : vector )
        std::cout << std::get< 0 >( temp ) << ' '       // print int
                  << std::get< 1 >( temp ) << ' '       // print const char*
                  << std::get< 2 >( temp ) << '\n';     // print float

}

/* output for me

-1 -one -1.2
0 zero 0
2 two 2.2
3 three 3.3
5 five 5.5
*/
