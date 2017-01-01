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


/// std::pair constructor
//  Constructs a new pair.

#include <iostream>
#include <utility>
#include <string>
#include <complex>
#include <tuple>


namespace k5 {

template<class T1, class T2>
std::ostream& operator << ( std::ostream& out, std::pair<T1, T2> pair){
    return out << pair.first << ", " << pair.second;
}

}

int main() {
    using k5::operator<<;   // exposes the operator << for pair objects
    // or
    // using namespace k5;  // is also okay

    std::pair< int, float > pair_1;
    std::cout << "value-initialized of pair_1 "
              << pair_1     // 0, 0
              << '\n';

    std::pair< int, double > pair_2( 43, 0.23 );
    std::cout << "the contents of pair_2 "
              << pair_2
              << '\n';

    std::pair< char, int > pair_3( pair_2 );
    std::cout << "implicitly converted (pair_3) "
              << pair_3
              << '\n';

    std::pair< std::complex< double >, std::string > pair_4(
                                                            std::piecewise_construct,
                                                            std::forward_as_tuple( 0.123, 7.7 ),
                                                            std::forward_as_tuple( 10, 'a' ) );
    std::cout << "piecewise constructed (pair_4) "
              << pair_4
              << '\n';








}


/* output for me:

value-initialized of pair_1 0, 0
the contents of pair_2 43, 0.23
implicitly converted (pair_3) +, 0
piecewise constructed (pair_4) (0.123,7.7), aaaaaaaaaa


*/


