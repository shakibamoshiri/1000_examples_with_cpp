/*
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

    1.2 handling of failure in exception handling
        > terminate             : function called when dynamic exception specification is violated
        > terminate_handler     : the type of the function called by std::terminate
        > get_terminate         : obtains the current terminate_handler
        > set_terminate         : changes the function to be called by std::terminate

    1.3 handling of exception specification violation
        > unexpected (deprecated since C++11)
        > bad_exception         : exception throw when dynamic exception specification is violated, if possible
        > unexpected_handler (deprecated since C++11)
        > set_unexpected (deprecated since C++11)
        > get_unexpected (deprecated since C++11)

    ********************************************************
2.  Exception Category
    Several convenience classes are predefined in the header <stdexcept> to report
    error conditions. These classes can be divided into two category: "logic error",
    and "runtime error". Logic errors are a consequence of faulty logic within the
    program and may be preventable. Runtime errors are due to events beyond the scope
    of the program and can not be easily predicted. (defined in header <stdexcpet>)

        > logic_error       : exception class to indicate violations of logical precondition or class invariants
        > invalid_error     : exception class to report invalid argument
        > domain_error      : exception class to report domain error
        > length_error      : exception class to report attempts to exceed maximum allowed size
        > out_of_range      : exception class to report argument outside of expected range
        > runtime_error     : exception class to indicate conditions only deletable at run time
        > range_error       : exception class to report errors in internal computations
        > overflow_error    : exception class to report arithmetic overflow
        > underflow_error   : exception class to report arithmetic underflow

    ********************************************************
3.  Error Number

        > errno                     : macro which expends to POSIX-compatible thread-local error number variable
        > E2BIG, EACCES, ..., EXDEV : macros for standard POSIX-compatible error conditions

    ********************************************************
4.  Assertion
        > static_assertion  : performs compile-time assertion checking
        > assert            : aborts the program if the user-specified condition is not true. May be disabled for release builds

    ********************************************************
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
