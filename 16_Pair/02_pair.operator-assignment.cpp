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


/// std::pair operator = (assignment)
//  Replaces the contents of the pair

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

    std::pair< std::string, std::string > pair_1( "the first string", "the second string" );

    std::pair< std::string, std::string > pair_2 = pair_1;      // copy assignment operator
    std::cout << pair_2 << '\n';

    std::pair< std::string, std::string > pair_3 = std::move( pair_1 );
    std::cout << pair_3 << '\n'
              << pair_1
              << '\n';



}


/* output for me:
the first string, the second string
the first string, the second string
,


*/


