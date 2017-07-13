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


/// std::make_pair
//  Swaps first with other.first and second with other.second

#include <iostream>
#include <utility>
#include <functional>

int main() {

    int number = 1;
    int array[ 5 ] = {1, 2, 3, 4, 5};

    // build a pair from two ints
    auto p1 = std::make_pair( number, array[ 1 ] );
    std::cout << "p1:\t" << p1.first << ' ' << p1.second << '\n';

    // build a pair from a reference to int and  an array (decayed to pointer)
    auto p2 = std::make_pair( std::ref( number ), array );
    number = 7;
    std::cout << "p2:\t" << p2.first << ' ' << *(p2.second + 1) << '\n';

}


/* output for me:
p1:     1 2
p2:     7 2
*/
