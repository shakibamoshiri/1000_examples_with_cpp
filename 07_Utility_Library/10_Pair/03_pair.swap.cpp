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


/// std::pair swap
//  Swaps first with other.first and second with other.second

#include <iostream>
#include <utility>

int main() {
    std::pair< int, int > p1, p2;

    p1 = std::make_pair( 23, 54 );

    p2.swap( p1 );

    std::cout << p2.first << ' ' << p2.second << '\n'; // 23 54

}


/* output for me:

*/
