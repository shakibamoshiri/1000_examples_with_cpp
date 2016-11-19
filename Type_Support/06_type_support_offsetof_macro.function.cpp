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
/// offsetof (function macro)
// The macro 'offsefof' expands to a constant of type std::size_t value of
// which is the offset in bytes, from the beginning of an object of specified
// type of its specified member, including padding if any.
//
// If type is not a standard layout type, the behavior is undefined
// If member if a static member or a member function, the behavior is undefined
// The offset of the first member of a standard-layout type is always zero
// (empty base optimization is mandatory)


#include <iostream>
#include <cstddef>

struct S {
    char ch;
    float f;
    int i;
    double d;
};

int main(){                                                                         // for me
    std::cout << "The first element is at offset " << offsetof(S,ch) << '\n'        // 0
              << "The second is at offset        " << offsetof(S,f)  << '\n'        // 4
              << "The third is at offset         " << offsetof(S,i)  << '\n'        // 8
              << "The fourth is at offset        " << offsetof(S,d)  << std::endl;  // 12
}
