
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
/// std::underlying_type
// template<class T> struct underlying_type {}
//
// If T is a template (since c++17) enumeration type, provides a member typedef
// type that names the underlying type of T. Otherwise, the behavior in undefined.

#include <iostream>
#include <type_traits>
#include <typeinfo>

enum e1 {};
enum class e2 : int {};

int main(){

    std::cout << ( std::is_same<unsigned, typename std::underlying_type<e1>::type >::value ? "unsigned" : "non-unsigned" ) << '\n';
    std::cout << ( std::is_same<int, typename std::underlying_type<e2>::type >::value ? "int" : "non-int" ) << '\n';

    // the output:
    // unsigned
    // int

}
