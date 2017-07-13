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
/// std::tie

//  Creates a tuple of l-value reference to its arguments or instances of std::ignore.

//  NOTE:
//  std::tie may be used to unpack a std::pair because
//  std::tuple has a converting assignment from pairs.




#include <iostream>
#include <tuple>
#include <string>
#include <set>

struct S {
    int number;
    std::string string;
    float floating;

    bool operator < ( const S& rhs ) const {
        // compares number to lhs.number
        // then string to rhs.string
        // then floating to rhs.floating
        return std::tie( number, string, floating ) < std::tie( rhs.number, rhs.string, rhs.floating );
    }
};


int main(){

    std::set< S > set_of_S; // S is LessThenComparable

    S value { 32, "string", 3.2 };  // it is initializer list, not a constructor!

    std::set< S >::iterator iterator;

    bool inserted = false;

    // unpacks the return value of insert into iterator and inserted
    std::tie( iterator, inserted ) = set_of_S.insert( value );

    if( inserted ) std::cout << "value was inserted successfully";

}

/* output for me
value was inserted successfully

*/
