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
/// std::is_extent
// If T an array type, provides the member constant value equal to the
// number of elements along the nth dimension of the array, if N is in
// [0, std::rank<T>::value]. For any other type, or if T is array of
// unknown bound along its first dimension and N is 0, value is 0.

#include <iostream>
#include <type_traits>

class A {};

int main() {

    endl( std::cout << std::extent<int>::value );           // 0
    endl( std::cout << std::extent<int[]>::value );         // 0
    endl( std::cout << std::extent<int[2]>::value );        // 2
    endl( std::cout << std::extent<int[2][3]>::value );     // 2
    endl( std::cout << std::extent<int[2],1>::value );      // 0
    endl( std::cout << std::extent<int[2],2>::value );      // 0
    endl( std::cout << std::extent<int[3][4],1>::value );   // 4
    endl( std::cout << std::extent<int[3][4],2>::value );   // 0

}
