/*
            Error Handling
            **************

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

*/
/// None of these has no examples

#include <iostream>
#include <exception>
#include <stdexcept>


int main(){ /* has no example */ }
