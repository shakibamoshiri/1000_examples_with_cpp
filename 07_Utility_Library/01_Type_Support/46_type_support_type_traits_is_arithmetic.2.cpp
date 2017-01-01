/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Type Traits (since C++11)
    Type traits defined a compile-time template-based interface to query or modify the
    properties of types. Any attempts to specialize any of the class template listed in
    This section results in undefined behavior, except that std::common_type may be
    specialized if the specialization depends on user-defined type

    (defined in header <type_traits>)

    Composite Type Categories
    > is_fundamental                 "                   fundamental type
    > is_arithmetic                  "                   arithmetic type
    > is_scalar                      "                   scalar type
    > is_object                      "                   object type
    > is_compound                    "                   compound type
    > is_reference                   "                   either l-value or r-value reference
    > is_member_pointer              "                   a pointer to a non-static member function or object
*/
/// std::is_arithmetic

#include <iostream>
#include <type_traits>

class A {};

int main() {

    std::cout << std::boolalpha;
    std::cout << "A:           " <<  std::is_arithmetic<A>::value << '\n';              // false
    std::cout << "int:         " <<  std::is_arithmetic<int>::value << '\n';            // true
    std::cout << "int const:   " <<  std::is_arithmetic<int const>::value << '\n';      // true
    std::cout << "int &:       " <<  std::is_arithmetic<int&>::value << '\n';           // false
    std::cout << "int *:       " <<  std::is_arithmetic<int*>::value << '\n';           // false
    std::cout << "float:       " <<  std::is_arithmetic<float>::value << '\n';          // true
    std::cout << "float const: " <<  std::is_arithmetic<float const>::value << '\n';    // true
    std::cout << "float &:     " <<  std::is_arithmetic<float&>::value << '\n';         // false
    std::cout << "float *:     " <<  std::is_arithmetic<float*>::value << '\n';         // false
}
