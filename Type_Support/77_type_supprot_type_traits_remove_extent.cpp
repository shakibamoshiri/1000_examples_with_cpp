
/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Type Modifications

Type modification template create new type definitions by applying modification of a
template parameter. The resulting type can then be accessed through type member typedef.

    > onst-volatile Specifier
    > remove_cv                 removes const or/and volatile specified form the given type
    > remove_const              "
    > remove_volatile           "
    > add_cv                    adds const or/and volatile specified to the given type
    > add_const                 "
    > add_volatile              "

    Reference
    > remove_reference          removes reference from the given type
    > add_lvalue_reference      adds l-value or r-value reference to the given type
    > add_rvalue_reference      "

    Pointer
    > remove_pointer            removes pointer from the given type
    > add_pointer               adds pointer to the given type

    Sing Modifiers
    > make_singed               makes the given integral type singed
    > make_unsigned             makes the given integral type unsigned

    Array
    > remove_extent             removes one extent from the given array type
    > remove_all_extents        removes all extents from the given array type
*/
/// std::remove_extent
// If T is an array of some type X, provides the member typedef type
// equal to X, otherwise type is T. Note that if T is a multidimension
// array, only the first dimension is removed.



#include <iostream>
#include <type_traits>
#include <iterator>
#include <algorithm>

template<typename T>
typename std::enable_if< std::rank<T>::value == 1>::type
print_1_d( const T& arr){

    copy(arr, arr+std::extent<T>::value, std::ostream_iterator< typename std::remove_extent<T>::type>(std::cout," "));

    std::cout << std::endl;
}


int main() {

    std::cout << std::rank<int>::value << '\n';         // 0        how many dimension
    std::cout << std::rank<int[3]>::value << '\n';      // 1
    std::cout << std::rank<int[3][3]>::value << '\n';   // 2

    std::cout << std::extent<int>::value << '\n';         // 0      length of the first dimension
    std::cout << std::extent<int[4]>::value << '\n';      // 4      length of the first dimension
    std::cout << std::extent<int[4][5]>::value << '\n';   // 4      "

    int arr[][3] = { {2,4,6}, {3,5,7} };

    std::cout << std::endl;
    print_1_d(arr[0]);
    print_1_d(arr[1]);
    print_1_d(arr[2]); // random value in memory


}
