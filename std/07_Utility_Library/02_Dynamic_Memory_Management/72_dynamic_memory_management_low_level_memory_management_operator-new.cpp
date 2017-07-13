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
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::new_handler
    > std::nothrow
*/
/// operatror new, operator new[]
// Allocates returned number of bytes. These allocation functions are called
// by new-expression to allocate memory in which new object would then be
// initialized. They may also be called using regular function call syntax.

#include <cstdio>
#include <cstdlib>

// replacement of a minimal set of function
void* operator new (std::size_t size){
    std::printf("global operator new was called, with size: %zu\n",size);
    return std::malloc(size);
}

void operator delete (void* ptr) noexcept {
    std::puts("global operator delete was called");
    std::free(ptr);
}

int main(){
    int* p1 = new int;
    delete p1;


    int* p2 = new int[10];
    delete [] p2;       // guaranteed to call the replacement in C++11
}
