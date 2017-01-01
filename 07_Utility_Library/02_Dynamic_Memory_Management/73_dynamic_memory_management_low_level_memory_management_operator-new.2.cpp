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
    *p1 = 1;
    std::printf("*p1 = %i\n", *p1);
    delete p1;

    int* p2 = new int(2);
    std::printf("*p2 = %i\n", *p2);
    delete p2;

    int* p3 = new int[3]; // array of int
    *p3 = 31;
    *(p3+1) = 32;
    *(p3 + 2) = 33;
    std::printf("p3[0] = %i\np3[1] = %i\np3[2] = %i\n", *p3, *(p3+1), *(p3+2));
    delete [] p3;
}
