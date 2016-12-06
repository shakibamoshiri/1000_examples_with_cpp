
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
/// std::enable_if
// template<bool B, class T = void> struct enable_if
//
// If B is true, std::enable_if has a public member typedef type, equal to T;
// otherwise, there is no member type.
//
// This metafunction is a convenient way to leverage SFINAE to conditionally
// remove function from overload resolution based on  type traits and to provide
// separate function overloads and specifications for different type traits.
// std::enable_if can be used as an additional function argument (not applicate to operator overload)
// as a return type (not applicate to constructors and destructors ), or as a
// class template of function template parameter.


#include <iostream>
#include <type_traits>
#include <typeinfo>


int main(){

    std::enable_if<true,int>::type t; // okay t is a int
    std::cout << (typeid(t) == typeid(int) ? "okay" : "not" ) << '\n';

    // std::enable_if<false, double>::type t; // ERROR there is no member type



}
