/*
            Error Handling
            **************

5.  System Error
    The header <system_error> defines types and functions used to report error
    conditions origination from the operating system, stream I/O, std::future
    or other low-level APIs.

        > error_category    : base class for errors categories
        > generic_category  : identifies the generic error category
        > system_category   : identifies the operating system error category
        > error_condition   : holds a portable error code
        > errc              : the std::error_condition enumeration listing all standard <cerror> macro constants
        > error_code        : holds a platform-dependent error code
        > error_system      : exception class used to report conditions that have an error_code
*/
/// std::error_code
//  std::error_code is a platform dependent code.
//  Each std::error_code object holds a pair of error code
//  operation from the operating system, or some low level
//  interface and a pointer to an object of typedef std::error_category,
//  which corresponds to the said interface. The error code-values
//  may be not unique across different error categories.

#include <iostream>
#include <system_error>
#include <thread>


int main() { /* has no example */ }
