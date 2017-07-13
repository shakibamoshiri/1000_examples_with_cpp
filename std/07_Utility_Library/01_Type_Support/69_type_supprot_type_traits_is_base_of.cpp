/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

    Type Relationship
    > is_same               checks if two types are the same
    > is_base_of            checks if a type is derived form the other type
    > is_convertible        checks if at ype can be converted to the other type
*/
/// std::is_base_of
// template <class Base, class Derived> struct is_base_of {}
//
// If "Derived" is derived form "Base" or if both are same non-union class,
// provides the member constant value equal to true. Otherwise value is false.

#include <iostream>
#include <type_traits>
#include <iomanip>

class A {};
class B : A {};
class C {};

int main() {

    std::boolalpha( std::cout );

    std::cout << "A is base of B " << std::is_base_of<A, B>::value << '\n';
    std::cout << "B is base of A " << std::is_base_of<B, A>::value << '\n';
    std::cout << "C is base of A " << std::is_base_of<C, A>::value << '\n';
    std::cout << "C base of itself " << std::is_base_of<C, C>::value << '\n';  // for the same type
}
