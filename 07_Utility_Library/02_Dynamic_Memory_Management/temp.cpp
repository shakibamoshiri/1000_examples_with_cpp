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
    > std::nothrow
*/
/// std::nothrow
//  std::nothrow is a constant of type std::nothrow_t used to disambiguate
//  the overloads of throwing and non-throwing allocation functions.

#include <iostream>
#include <new>


int main(){
    try {
        while (true){
            new int[10000000000ul]; // throwing overload
        }
    } catch (const std::bad_alloc& er){ std::cout << "first: " << er.what() << std::endl; }

    while (true){
        int* ptr = new (std::nothrow) int[10000000000ul];   // non-throwing overload
        if (ptr == nullptr){
            std::cout << "second: allocation returned nullptr\n";
            break;
        }
    }

}
