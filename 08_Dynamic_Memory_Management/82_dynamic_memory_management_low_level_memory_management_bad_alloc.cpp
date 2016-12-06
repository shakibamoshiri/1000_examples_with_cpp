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
    > std::get_new_handler
    > std::set_new_handler
    > std::bad_alloc
    > std::bad_array_new_length
    > std::nothrow_t
    > std::new_handler
    > std::nothrow
*/
/// std::bad_alloc
//  std::bad_alloc is the type of the object thrown as exception by
//  the allocation functions to report failure to allocate storage.

#include <iostream>
#include <new>



int main(){


    try {
        while(true) new int[10000000000ul];
    } catch (const std::bad_alloc& er){ std::cout << "Allocation failed ... " << er.what() << std::endl; }
}
