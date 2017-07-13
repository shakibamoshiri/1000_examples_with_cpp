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
/// std::remove_cv and std::remove_const and std::remove_volatile
// Provides the member typedef type which is the same of as T,
// except that its topmost cv-qualifiers are removed.


#include <iostream>
#include <type_traits>
#include <iomanip>
#include <typeinfo>


int main() {

    std::boolalpha( std::cout );

    std::remove_const<const int>::type i;
    std::remove_volatile<volatile float>::type f;
    std::remove_cv<const volatile double>::type d;

    std::cout << "i is a: " << (typeid(i)==typeid(int) ? "int" : "not a int" ) << '\n';
    std::cout << "f is a: " << (typeid(f)==typeid(float) ? "float" : "not a float" ) << '\n';
    std::cout << "d is a: " << (typeid(d)==typeid(double) ? "double" : "not a double" ) << '\n';

}
