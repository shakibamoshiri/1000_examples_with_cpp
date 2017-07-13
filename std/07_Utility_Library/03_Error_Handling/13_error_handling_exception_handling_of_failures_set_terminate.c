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
/// std::set_terminate
//  Make 'f' (parameter) the new global terminate handler function
//  and returns the previously installed std::terminate_handler
//  This function is thread-safe. Every call to std::set_terminate
//  synchronized-with the subsequent std::set_terminate and std::get_terminate.

#include <iostream>

int main(){ /* has no example; */ }
