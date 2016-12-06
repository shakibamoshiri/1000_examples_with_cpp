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
#include <iostream>

// class-specific allocation function
struct X {
    int day;

    X(int t): day(t) {}
    X() = default;

    static void* operator new (std::size_t size){
        std::cout << "custom new for size: " << size << std::endl;
        return ::operator new(size);
    }

    static void* operator new[] (std::size_t size){
        std::cout << "custom new[] for size: " << size << std::endl;
        return ::operator new(size);
    }
};

int main(){

    X* p1 = new X(3);
    std::cout << p1->day << std::endl;
    delete p1;

    X* p2 = new X[4];
//    X* const tmp = p2;
    p2->day = 4;
    (p2+1)->day = 5;
    (p2+2)->day = 6;
    (p2+3)->day = 7;

// does not work correctly
//    p2->day = 1;
//    ++p2->day = 2;
//    ++p2->day = 3;
//    (++p2)->day = 4;
//    p2 -= 3;


    std::cout << p2->day << ' ' << (p2+1)->day << ' ' << (p2+2)->day << ' ' << (p2+3)->day << std::endl;
    delete [] p2;
}
