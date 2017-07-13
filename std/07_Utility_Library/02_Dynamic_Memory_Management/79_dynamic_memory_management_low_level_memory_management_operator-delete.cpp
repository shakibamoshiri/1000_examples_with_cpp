/*
        Dynamic Memory Management
        *************************


Low Level Memory Management (defined is header <new>)

    The new-expression is the only way to create an object or an array of object
    with dynamic storage duration, that is, with lifetime not restricted to the
    scope in which it is created.
    A new-expression obtains storage by calling an allocation function. A delete-expression
    destroys a most derived object or an array created by a new-expression and calls
    the deallocation function. The default allocation and deallocation functions, along
    with related functions types, and objects, are declared in the header <new>.

    > operator new
    > operator delete
    > std::set_new_handler
    > std::get_new_handler
    > std::bad_alloc
    > std::bad_array_new_length
    > std::nothrow_t
    > std::new_handler
    > std::nothrow
*/
/// operatror delete, delete []
// Deallocates storage previously allocated by a matching operator new.
// These deallocation functions are called by delete-expression and by
// new-expression to deallocation memory after destructing (or failing
// to construct) objects with dynamic storage duration. They may also be
// called using regular function call syntax.
//
/// NOTE:
// In all cases, if ptr (i.e void* ptr) is a null pointer, the standard
// library deallocation do nothing. If the pointer passed to the standard
// library deallocation function was not obtained from the corresponding
// standard library allocation functions, the behavior is undefined.
//
/// NOTE:
// After the standard library deallocation function returns, all pointers
// referring to any part of the deallocation storage become invalid.
//
/// NOTE:
// Any use of a pointer that became invalid in this manner, even copying
// the pointer value to another variable, is undefined behavior.
//
/// NOTE:
// Indirection through a pointer that became invalid in this manner and passing
// it to a deallocation function (double-delete) is undefined behavior.
// Any other use is implementation-defined.

#include <iostream>

int main(){
//    see
//    72#low_level_memory_management_operator-new.cpp
//    73#low_level_memory_management_operator-new.2.cpp
//    74#low_level_memory_management_operator-new.3.cpp
//    75#low_level_memory_management_operator-new.4.cpp
//    76#low_level_memory_management_operator-new.5.cpp
//    77#low_level_memory_management_operator-new.6.cpp
//    78#low_level_memory_management_operator-new.7.cpp
}
