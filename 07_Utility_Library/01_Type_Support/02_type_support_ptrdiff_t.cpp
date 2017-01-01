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
/// std::ptrdiff_t
// std::size_t is the unsigned integer type of the result of the sizeof operator
// as well as the sizeof... operator and the alignof operator (since C++11)
//
// NOTE:
// std::ptrdiff_t is used for pointer arithmetic and array indexing, if negative value are possible.
// Programs that use other type such as int, may fall on, e.g. 64-bit systems when the index exceeds
// INT_MAX of if relies on 32-bit modular arithmetic.
// When working C++ container library, the proper for the different between iterator it
// the member typedef different_type, which is often synonymous with std::ptrdiff_t.
// Only pointers to elements of the same array (including the pointer one past the end
// of the array) may be subtracted form the other.
// For char arrays shorter than PTRDIFF_MAX, std::ptrdiff_t acts as the singed counterpart
// of std::size_t: it can store the size of the array on any type and is, on most platform,
// synonymous with std::inptr_t

#include <iostream>
#include <cstddef>

int main(){

    const std::size_t N = 10;
    int* ptr = new int[N];
    int* ptr2end = ptr + N;
    for(std::ptrdiff_t i = N; i > 0; --i) *(ptr2end - i) = i;

    for(std::size_t i = 0; i < N; ++i) std::cout << *(ptr + i) << ' ';

    delete [] ptr;

}
