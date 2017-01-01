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
/// std::swap( std::tuple );

//  Swaps the contents of 'lhs' and 'rhs'.
//  Equivalent to lhs.swap( rhs ).




#include <iostream>
#include <tuple>



int main(){

    // okay the answer is there is different between float type
    // and double type
    // this case is not with assignment operator but is is with
    // swap
    //
    // swap( float, double ); does not compile

    {
        std::tuple< int, float, const char* > one( 1, 1.1, "one" );
        std::tuple< int, float, const char* > one_again( 1, 1.1, "one" );

        std::cout << ( one == one_again ? "true" : "false" ) << '\n';
    }


    {
        std::tuple< int, float, const char* > one( 1, 1.1, "one" );
        auto one_again = one;

        std::cout << ( one == one_again ? "true" : "false" ) << '\n';
    }

    // the same syntax but with auto and std::make_tuple
    {
        std::tuple< int, float, const char* > one( 1, 1.1, "one" );
        auto one_again = std::make_tuple( 1, 1.1, "one" );

        std::cout << ( one == one_again ? "true" : "false" ) << '\n';
    }


    {

        double d = 1.1;
        float one = d;
        float one_again = 1.1;

        std::cout << (one == one_again ? "true" : "false" ) << '\n';
    }

    // the same problem with the swap:
    {
        std::tuple< int, float, const char* > one( 1, 1.1, "one" );
        auto one_again = std::make_tuple( 2, 2.2, "two" );

        std::swap( one, one_again );
    }

    // when swapping the compiler says:
    // error: no matching function for call to swap(std::tuple<int, float, const char*>&,
    //                                              std::tuple<int, double, const char*>&)

    // then I thought may be the problem is with the assignment operator
    // when it wants to assign each corresponding type,
    // but the assignment operator has no problem with float or double
    {
        std::tuple<int, float, const char*> one(1, 1.1, "one" );
        std::tuple<int, double, const char*> two(2, 2.2, "two" );
        one.swap( two );
        std::cout << std::get< 1 >( one );
    }
}

/* output for me


*/

// ask in stackoverflow


/* what type does the std::make_tuple, when returning to a auto type?

    I am confusing in the return type of std::make_tuple to a std::tuple
    when the type is auto.

    Say I have:
    std::tuple< int, const char* > t1( 1, "one" );
    std::tuple< int, const char* > t1_again ( 1, "one" );

    the output of the comparison these tuple object is "true"

    std::cout << ( t1 == t1_again ? "true" : "false" ); // true

    but If would have:
    std::tuple< int, const char* > t1( 1, "one" );
    auto t1_again = std::make_tuple ( 1, "one" );

    then the output of comparison is "false"!

    std::cout << ( t1 == t1_again ? "true" : "false" ); // true

*/

