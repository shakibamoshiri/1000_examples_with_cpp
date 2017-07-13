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
//
/// NOTE:
// Custom placement forms of operator new cab be used for any
// purpose, for example, to fill the allocated array of character.

#include <iostream>
#include <algorithm>

void* operator new[] (std::size_t size, char ch){

    void* ptr = operator new[](size);

    std::fill_n(reinterpret_cast<char*>(ptr), size, ch);

    return ptr;
}

int main() {
    char* p = new ('@') char[10];
    p[9] = '\0'; // puts null-terminates

    std::cout << p << '\n';

    delete [] p;
}















