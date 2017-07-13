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
/// system_category
// Obtains a reference to the static error category for errors reported by
// operating system.

#include <iostream>
#include <system_error>
#include <string>
#include <cerrno>

int main(){

    std::error_condition econd = std::generic_category().default_error_condition(EDOM);

    std::cout << "Category: " << econd.category().name() << '\n'
              << "Value   : " << econd.value()           << '\n'
              << "Message : " << econd.message()         << std::endl;

    econd = std::system_category().default_error_condition(10001);

    std::cout << "Category: " << econd.category().name() << '\n'
              << "Value   : " << econd.value()           << '\n'
              << "Message : " << econd.message()         << std::endl;

}
