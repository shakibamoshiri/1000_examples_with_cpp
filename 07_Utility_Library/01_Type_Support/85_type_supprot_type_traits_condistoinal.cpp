
/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Miscellaneous Transformations (in header <type_traits>
    > aligned_storage           defines the type suitable for use as uninitialized storage for type of given size
    > aligned_union             defines the type suitable for use as uninitialized storage for all given types
    > decay                     applies type transformations as when passing a function argument by value
    > enable_if                 hides a function overload or template specialization based on compile-time boolean
    > conditional               chooses one type of another based on compile-type boolean
    > common_type               deduces the result type of mixed-mode arithmetic expression
    > underlying_type           obtains the underlying integer type for a given enumeration type
    > result_of                 deduces the return type of a function call expression
    > void_t                    void variadic alias template

*/
/// std::conditional
// template<bool B,class T, class U> struct conditional {}
//
// Provides member typedef type, which is defined as T if B
// is true at compile time, or as F is B is false


#include <iostream>
#include <type_traits>
#include <typeinfo>

int main(){

    std::boolalpha( std::cout );

    std::cout << std::is_same< int, std::conditional<true, int,float>::type >::value << '\n';       // true
    std::cout << std::is_same< int, std::conditional<false, int,float>::type >::value << '\n';      // false

    std::cout << std::is_same< float, std::conditional<false, int,float>::type >::value << '\n';    // true
    std::cout << std::is_same< float, std::conditional<true, int,float>::type >::value << '\n';     // false
}
