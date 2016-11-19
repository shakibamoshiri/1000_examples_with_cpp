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
/// std::size_t
// std::size_t is the unsigned integer type of the result of the sizeof operator
// as well as the sizeof... operator and the alignof operator (since C++11)
//
// NOTE:
// std::size_t can store the maximum size of a theoretically possible object of any
// type (including array). A type whose size cannot be represented by std::size_t
// is ill-formated (since C++14). On many platform (an exception is systems with
// segmented addressing) std::size_t can safely store the value of any non-member
// pointer, in which case it is synonymous with std::unitptr_t.

#include <iostream>
#include <cstddef>

int main(){

    const std::size_t N = 10;
    int* ptr = new int[N];

    for(std::size_t sz = 0; sz < N; ++sz) ptr[sz] = sz;

    // reverse cycle are tricky for unsigned type
    for(std::size_t sz = N; sz-- > 0; ) std::cout<<ptr[sz]<<' ';

    delete []  ptr;
}
