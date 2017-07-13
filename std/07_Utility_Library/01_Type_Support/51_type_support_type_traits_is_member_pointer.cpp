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
/// std::is_member_pointer

#include <iostream>
#include <type_traits>

int main() {

    class cls {};

    std::cout << std::boolalpha;
    std::cout << std::is_member_pointer<int>::value << '\n';            // false
    std::cout << std::is_member_pointer<int*>::value << '\n';           // false
    std::cout << std::is_member_pointer<cls>::value << '\n';            // false
    std::cout << std::is_member_pointer<int (cls::*)>::value << '\n';   // true
}
