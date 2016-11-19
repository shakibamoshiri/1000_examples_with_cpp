/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Additional basic types and macros
    > size_t            unsigned integer type returned by the sizeof operator (typedef)
    > ptrdiff_t         signed integer type returned when subtracting two pointer(typedef)
    > nullptr_t         the type of the null pointer literal nullptr (typedef)
    > NULL              implementation-defined null pointer constant (macro constant)
    > max_align_t       POD type with alignment requirement as great as any other scalar type (typedef)
    > offsetof          byte offset from the beginning of a standard-layout type to specified member (function macro)

*/
/// std::max_align_t
// std::max_align_t is a POD (Plain Old Data) type whose alignment requirement is
// at least as strict (as large) as that of even scalar type.
//
// NOTE:
// Pointers returned by allocation functions such as std::malloc are suitably
// aligned for any object, which means they are aligned at least as strict as
// std::max_align_t.
//
// std::max_align_t usually synonymous with the largest scalar type, which is
// long double on most platform, and its alignment requirement either 8 or 16.


#include <iostream>
#include <cstddef>

int main(){ endl( std::cout << alignof(std::max_align_t) ); } // for me 8 but for you may be 16
