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
/// std::system_error
//  std::system_error is the type of the exception thrown by various
//  library functions (typically the functions that interface with the
//  OS facilities, e.g. the constructor of std::thread) when the
//  exception has an associated std::error_code, which may be reported.

#include <thread>
#include <iostream>
#include <system_error>

int main()
{
    try { std::thread().detach(); }     // attempt to detach a non-thread
    catch(const std::system_error& e) {
        std::cout << "Caught system_error with code " << e.code()
                  << " meaning " << e.what()          << std::endl;
    }
}
