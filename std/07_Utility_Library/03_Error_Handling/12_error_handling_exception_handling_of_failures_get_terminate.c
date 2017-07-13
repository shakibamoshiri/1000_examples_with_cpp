/*
            Error Handling
            **************

1.  Exception Handling:
    The header <exception> provides several classes and function related
    to exception handling in C++ program. (defined in header <exception>)

    1.2 handling of failure in exception handling
        > terminate             : function called when dynamic exception specification is violated
        > terminate_handler     : the type of the function called by std::terminate
        > get_terminate         : obtains the current terminate_handler
        > set_terminate         : changes the function to be called by std::terminate

*/
/// std::get_terminate
//  Returns the currently installed std::terminate_handler
//  which may be a null pointer.
//  The function is thread-safe. Prior call to std::set_terminate
//  synchronized-with (see std::memory_order) this function.

#include <iostream>

int main(){ /* has no example; */ }
