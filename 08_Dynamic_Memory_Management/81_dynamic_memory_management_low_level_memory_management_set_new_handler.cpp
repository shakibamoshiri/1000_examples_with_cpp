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
/// std::set_new_handler
// Makes new_p (argument) the new global new-handler function and returns the
// previously installed new-handler.
// The "new-handler" function is the function called by allocation function
// whenever a memory allocation attempt fail.
// Its intended purpose is one of there things:
// 1)   make more memory available
// 2)   terminate the program (e.g. by calling std::terminate)
// 3)   throw exception of type std::bad_alloc or derived form std::bad_alloc
//
// The default implementation throws std::bad_alloc. The user can install his
// own new-handler, which may offer behavior different than the default one.
//
// If new-handler returns, the allocation function repeats the previously-failed
// allocation attempts and calls the new-handler again if the allocation fails
// again. To end the loop, new-handler may call std::set_new_handler(nullptr):
// if, after a failed allocation attempts, allocation function finds that
// std::set_new_handler returns a null pointer value, it will throw std::bad_alloc
// At program startup, new-handler is a null pointer.
//
// This function is thread-safe. Even call to std::set_new_handler synchronizes-with
// (see std::memory_order) the subsequent std::set_new_handler and std::get_new_handler calls.

#include <iostream>
#include <new>

// user defined
void handler (){
    std::cout << "Memory allocation failed, terminating..." << std::endl;
    std::set_new_handler(nullptr);
}


int main(){
    std::set_new_handler(handler);

    try {
        while(true) new int[10000000000ul];
    } catch (const std::bad_alloc& er){ std::cout << er.what() << std::endl; }
}
