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
/// std::nullptr_t
// std::nullptr_t is the type of  the null pointer literal, nullptr
// It is a distinct type that is not itself a pointer type or a pointer
// to member type.

#include <iostream>
#include <cstddef>


/// Example:
// If two more overload accept different pointer type, an overload for
// std::nullptr_t is necessary to accept a null pointer argument

void func (int*){ std::cout << "Pointer to integer overload\n"; }

void func (double*){ std::cout << "Pointer to double overload\n"; }

void func (std::nullptr_t){ std::cout << "null pointer overload\n"; }



int main(){
    int* ptr_int;
    double* ptr_double;

    func(ptr_int);      // calls func (int*)
    func(ptr_double);   // calls func (double*)
    func(nullptr);      // calls func (nullptr_t);
}
