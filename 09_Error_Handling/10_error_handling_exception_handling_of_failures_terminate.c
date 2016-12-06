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
/// std::terminate
//  std::terminate() is called by c++ runtime when exception
//  handling fail.
//
//  std::terminate() may be called the directly from the program
//
// In any case, std::terminate calls the currently installed std::terminate_handler
//  later led to terminate being called.

//  There are some reason for this, that you can see the main website.

#include <iostream>

int main(){ /* has no example; */ }
