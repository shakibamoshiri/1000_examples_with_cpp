/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

    Support Operation
    (I skipped this part) you can read the main site

    Property Query
    > alignment_of           obtains the type's alignment requirement (class template)
    > rank                  obtains the number of dimensions of an array type (class template)
    > extent                obtains the size of an array type along a specified dimension (class template)
*/
/// std::is_rank
// If T is an array type, provides the member constant value equal
// to the number of dimensions of the array. For any other type, value is 0.

#include <iostream>
#include <type_traits>

class A {};

int main() {

    endl( std::cout << std::rank<int>::value );         // 0
    endl( std::cout << std::rank<int[1]>::value );      // 1
    endl( std::cout << std::rank<int[1][2]>::value );   // 2
    endl( std::cout << std::rank<int[1][2][3]>::value );// 3
}
