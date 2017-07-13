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
/// std::terminate_handler
//  std::terminate_handler is a function pointer type (pointer to function
//  that takes no arguments and returns void), which is installed and queried
//  by the functions std::set_terminate and std::get_terminate and called
//  by std::terminate.
//
//  The c++ implementation provides a default std::terminate_handler
//  function, which call std::abort.

#include <iostream>

int main(){ /* has no example; */ }
