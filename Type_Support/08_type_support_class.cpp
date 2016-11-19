/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Numeric Limits (defined in header <limits>)
    > umeric_limits                     provide an interface to query properties of all fundamental numeric types (class  template)
    Template parameters
    T 	- 	a type to retrieve numeric properties for
Member constants
    is_specialized      identifies types for which std::numeric_limits is specialized
    is_signed           identifies signed types
    is_integer          identifies integer types
    is_exact            identifies exact types
    has_infinity        identifies floating-point types that can represent the special value "positive infinity"
    has_quiet_NaN       identifies floating-point types that can represent the special value "quiet not-a-number" (NaN)
    has_signaling_NaN   identifies floating-point types that can represent the special value "signaling not-a-number" (NaN)
    has_denorm          identifies the denormalization style used by the floating-point type
    has_denorm_loss     identifies the floating-point types that detect loss of precision as denormalization loss rather than inexact result
    round_style         identifies the rounding style used by the type
    is_iec559           identifies the IEC 559/IEEE 754 floating-point types
    is_bounded          identifies types that represent a finite set of values
    is_modulo           identifies types that handle overflows with modulo arithmetic
    digits              number of radix digits that can be represented without change
    digits10            number of decimal digits that can be represented without change
    max_digits10        number of decimal digits necessary to differentiate all values of this type
    radix               the radix or integer base used by the representation of the given type
    min_exponent        one more than the smallest negative power of the radix that is a valid normalized floating-point value
    min_exponent10      the smallest negative power of ten that is a valid normalized floating-point value
    max_exponent        one more than the largest integer power of the radix that is a valid finite floating-point value
    max_exponent10      the largest integer power of 10 that is a valid finite floating-point value
    traps               identifies types which can cause arithmetic operations to trap
    tinyness_before 	identifies floating-point types that detect tinyness before rounding

*/
/// std::numeric_limit (in header <limit> | template <class T> class numeric_limit )
// The numeric limit class template provides a standardized way to query
// various properties of arithmetic type (e.g. the largest possible value
// for type int is std::numeric_limit<int>::max() ).
// This information is provided via specialization of the numeric_limit template.
//
// Additionally, a specialization exists for every cv-qualified version of each
// arithmetic type, identical to the unqualified specialization, e.g. std::numeric_limit<const int>,
// std::numeric_limit<volatile int>, and std::numeric_limit<const volatile int> are provide
// and are equivalent to std::numeric_limit<int>.
//
// The standard library types are aliases of arithmetic type (such as std::size_t, or std::streamsize)
// may also be examined with std::numeric_limit type traits
//
// Non-arithmetic standard type such as std::complex<T> or std::nullptr_t do not have specialization
//
//

#include <iostream>
#include <limits>
#include <iomanip>


int main(){

    std::cout << "type:\t"  << "lowest:\t"  << "highest:" << '\n'
              << "int\t"    << std::numeric_limits<int>::lowest()    << '\t' << std::numeric_limits<int>::max()    << '\n'
              << "float\t"  << std::numeric_limits<float>::lowest()  << '\t' << std::numeric_limits<float>::max()  << '\n'
              << "double\t" << std::numeric_limits<double>::lowest() << '\t' << std::numeric_limits<double>::max() << std::endl;

}
