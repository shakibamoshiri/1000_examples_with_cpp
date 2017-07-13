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
/// error_condition
//  std::error_condition is a platform-independent error code.
//  Like std::error_code, it is uniquely identified by an integer
//  value and a std::error_category, but unlike std::error_code.
//  The value is not platformed-dependent.

int main() { /* has no example */ }
