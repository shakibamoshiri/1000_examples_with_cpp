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
    std::get( std::tuple )      tuple accesses specified element
    operator ==                 lexicographically compares the value of tuples
    operator !=                 "
    operator >                  "
    operator <                  "
    operator <=                 "
    operator >=                 "
    std::swap ( std::tuple )    specializes the std::swap algorithm



*/
/// std::forward_as_tuple

//  Constructs a tuple of reference to the argument
//  is 'arts'suitable for forwarding as an argument
//  to a function. The tuple has  r-value reference
//  date member when r-value are used as argument -
//  and otherwise has l-value reference date members.



#include <iostream>
#include <tuple>
#include <string>
#include <map>



int main(){

    std::map< int, std::string > map;

    map.emplace( std::piecewise_construct,
                 std::forward_as_tuple( 10 ),
                 std::forward_as_tuple( 10, 'A' ) );

    std::cout << "map[ 10 ] == "
              << map[ 10 ] << '\n';

    // the following is an error: it produces a
    // std::tuple< int&&, int&& >
    // holding to dangling references.
    //
    // auto t = std::forward_as_tuple( 20, 'A' );
    // map.emplace( std::piecewise_construct, std::forward_as_tuple( 10 ), t );

}

/* output for me


*/
