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
/// std::add_cv , add_const, add_volatile
//

#include <iostream>
#include <type_traits>
#include <iomanip>
#include <typeinfo>

struct S {
    void f() { std::cout << "Non-constant\n"; }
    void f() const { std::cout << "constant\n"; }
};

template<typename T> void call_f (){
    T().f(); // calls f() or f() const
}

int main() {

    call_f<S>(); // Non-constant

    call_f<std::add_const<S>::type>();  // constant
}
