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
/// error_category
// std::error_category serves as the base class for specific error
// category types, such as std::system_category, std::iostream_category
// , etc. Each specific category class defines the error_code, error_condition
// mapping and holds the explanatory strings for all error_condition.
// The objects of error_category classes are treated as singletons, passed by reference.
