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
// The keyword static is optional for these functions whether used or not,
// the allocation function is a static member function.
//
/// NOTE:
// Overloads of operator new and operator new[] with additional used-defined
// parameters ("placement forms", version 11 and 12) may also be defined as
// class members.
// When the placement new expression with the matching signature looks for the
// corresponding allocation function to call, it begins at class scope before
// examining the global scope, and if class-specific placement new is provided
// it is called.

#include <iostream>
#include <stdexcept>

struct User_Defined {
    User_Defined(){ throw std::runtime_error(""); }

    // custom placement new
    static void* operator new (std::size_t size, bool b){
        std::cout << "custom placement new was called with boolean: " << b << '\n';
        return ::operator new(size);
    }

    // custom placement delete
    static void operator delete (void* ptr, bool b){
        std::cout << "custom placement delete was called with boolean: " << b << '\n';
        ::operator delete(ptr);
    }
};

int main(){

    try { User_Defined* ptr = new (true) User_Defined;}
    catch (const std::exception&){}

    std::cout << "there was no exception\n";

}



