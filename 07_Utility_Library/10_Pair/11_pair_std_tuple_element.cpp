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

/// std::tuple_element< std::pair >
//  The partial specialization of std::tuple_element for pairs provide compile-time
//  access to the types of the pairs' elements using tuple-like syntax.

#include <iostream>
#include <string>
#include <tuple>


template< int N, typename T, typename U >
static auto constexpr get( std::pair< T, U > const& pair ) -> typename std::tuple_element< N, decltype( pair ) >::type // return type
{
    return N == 0 ? pair.first : pair.second;
}


int main() {

    auto var = std::make_pair( 2, std::string( "two" ) );

    std::cout << get< 0 >( var ) << " == "
              << get< 1 >( var ) << std::endl;      // 2 == two

}



/* output for me:



*/
