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


/// std::get( std::pair )
//  Extracts an element from the pair using tuple-like interface.

#include <iostream>
#include <utility>
//#include <vector>
//#include <algorithm>
//#include <string>

int main() {

    std::pair< int, int > int_double( 1, 3 );

    /// NOTE:
    // this case is ambiguous for complier
    std::get< int >( int_double ) = 44;

    std::cout << int_double.first << ' ' << int_double.second;

}



/* output for me:



*/
