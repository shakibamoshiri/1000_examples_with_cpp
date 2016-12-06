
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
/// std::aligned_storage
// template<std::size_t Len, std::size_t Align> struct alinged_storage {}
//
// Provides the member typedef type, which is a POD Type suitable for use as
// uninitialized storage for any object whose size at most 'Len' and whose
// alignment requirement is a divisor of 'Align'.
// The default value of 'Align' is the most stringent (the largest) alignment
// requirement for any object whose size is at most 'Len'. If the default value
// is not used, 'Align' must be the value of the alignof(T) for some type T. or
// the behavior is undefined.
// The behavior is undefined if Len == 0.



#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>


typedef std::aligned_storage<sizeof (int), std::alignment_of<double>::value>::type New_type;

int main(){

    std::cout << "alignment_of<int> == "
              << std::alignment_of<int>::value << std::endl;
    std::cout << "aligned to double == "
              << std::alignment_of<New_type>::value << std::endl;

}
