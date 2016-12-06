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
        > exception_ptr         : shared pointer type for handling exception objects
        > make_exception_ptr    : creates an std::exception_ptr from an exception object
        > current_exception     : capture the current exception in a std::exception_ptr
        > rethrow_exception     : throw an exception from a std::exception_ptr
        > nested_exception      : a mixin type to capture and store current exceptions
        > throw_with_nested     : throw its argument with std::nested_exception mixed in
        > rethrow_if_nested     : throw the exception from a std::nested_exception

*/
/// std::rethrow_exception
// Throw the previously captured exception object, referred
// to by the exception pointer 'p' (parameter)

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

void handle_eptr (std::exception_ptr eptr){     // passing by value is okay
    try {
        if (eptr)       // by default it is null
            std::rethrow_exception(eptr);
    } catch (const std::exception& er){ std::cout << "caught exception \"" << er.what() << "\"\n"; }
}

int main(){
    std::exception_ptr eptr;

    try { throw std::out_of_range("out_of_range"); }
    catch (...) { eptr = std::current_exception(); }

    handle_eptr(eptr);

}   // destructor for std::out_or_range called here, when the eptr is destruct
