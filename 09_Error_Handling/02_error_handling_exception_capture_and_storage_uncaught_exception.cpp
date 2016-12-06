/*
            Error Handling
            **************


1.  Exception Handling:
    The header <exception> provides several classes and function related
    to exception handling in C++ program. (defined in header <exception>)

    1.1 capture and storage of exception object
        > exception             : base class for exceptions thrown by the standard library components
        > uncaught_exception    : checks if exception handling is currently is progress
        > uncaught_exceptions   : "
        > make_exception_ptr    : shared pointer type for handling exception objects
        > current_exception     : capture the current exception in a std::exception_ptr
        > rethrow_exception     : throw an exception from a std::exception_ptr
        > nested_exception      : a mixin type to capture and store current exceptions
        > throw_with_nested     : throw its argument with std::nested_exception mixed in
        > rethrow_if_nested     : throw the exception from a std::nested_exception

*/
/// std::uncaught_exception     ->    deprecated in c++17
/// std::uncaught_exceptions    ->    since c++17


#include <iostream>
#include <exception>
#include <stdexcept>

struct Bird {
    ~Bird(){
    if (std::uncaught_exception()) std::cout << "~Bird() was called during stack unwinding\n";
    else std::cout << "~Bird() was called normally\n";
    }
};

int main(){
    Bird b;

    try {
        Bird b;
        std::cout << "Exception thrown...\n";

        throw std::runtime_error("test of exception");

    } catch (const std::exception& er){ std::cout << "Exception caught: " << er.what() << '\n'; }


}
