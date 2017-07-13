/*

        std::pair
        *********
defined in header <utility>

Template Parameter:
    T1, T2

Member Type:
    first_type          T1
    second_type         T2

Member Object:
    first               T1
    second              T2
Member function:
    constructor         constructs a new pair
    operator =          assigns the contents
    swap (c++11)        swaps the contents

Non-member Function:
    make_pair
    operator ==                         lexicographically compares the values in the pair
    operator !=                         "
    operator <                          "
    operator >                          "
    operator <=                         "
    operator >=                         "
    std::swap( std::pair )              specialized the std::swap algorithm
    std::get( std::pair )               accesses an element of a pair

Helper Classes:
    std::tuple_size< std::pair >        obtains the size of a pair
    std::tuple_element< std::pair >     obtains the type of the elements of pair

*/


/// std::tuple_size< std::pair >
//  The partial specialization of std::tuple_size for pairs provides
//  a compile-time way to obtain the number of elements in a pair, which
//  is always 2, using tuple-like syntax.

#include <iostream>
#include <utility>
#include <tuple>
//#include <vector>
//#include <algorithm>
//#include <string>

template< typename T >
void size_of( T how_many ){

    int array[ std::tuple_size< T >::value ];   // can be used at compile time

    std::cout << std::tuple_size< T >::value;   // or at runtime
}


int main() {

    size_of( std::make_tuple( 1, 2, 3 ) );  // 3
    size_of( std::make_pair( 'c', 'c' ) );  // 2

}



/* output for me:



*/
