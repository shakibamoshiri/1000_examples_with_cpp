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
#include <string>



int main(){

    std::string str( "tuple" );
    auto tuple = std::make_tuple( 2, 'c', str );
    auto tuple_2 = std::make_tuple( 2, 'c', str );

    bool et = ( tuple == tuple_2 );

    if( et ) std::cout << "they both are the same";



}

/* output for me


*/
