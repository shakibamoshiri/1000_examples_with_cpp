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
/// NULL
// The macro NULL is an implementation-defined null pointer constant
// which may be an integral expression r-value of integer type that
// evaluates to zero or a pr-value of type std::nullptr_t
//
// an integer literal with value zero, or a pr-value of type std::nullptr_t
//
// A null pointer constant may be implicitly converted to any pointer type;
// such conversion results the null pointer value of that type. If a null
// pointer constant has integer type, it may be converted to a pr-value
// of type std::nullptr_t
//
// NOTE: in C, the macro NULL may have the type void*, but that is not allowed in C++


#include <iostream>
#include <cstddef>

class M;

int main(){

    int* ptr = NULL;
    int* ptr2 = static_cast<std::nullptr_t>(NULL); // since c++11   #define NULL nullptr

    void (*func_ptr)(int) = NULL;

    int M::* mptr = NULL;
    void (M::* func_mptr)(int) = NULL;
}
