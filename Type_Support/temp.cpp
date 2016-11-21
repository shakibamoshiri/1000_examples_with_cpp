
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
/// std::aligned_union
// template <std::size_t Len, class... Types> struct aligned_union;
//
// Provide the member typedef type, which is a POD type of size and
// alignment suitable for use as uninitialized storage for an object
// of any of the types listed in 'Types'. The size of the storage is at
// least 'Len'. std::aligned_union also determines the strictest (largest)
// alignment requirement amount all Types and makes it available as the
// constant alignment_value.
// If sizeof ... (Types) == 0 the behavior is undefined.

#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>



int main(){}
