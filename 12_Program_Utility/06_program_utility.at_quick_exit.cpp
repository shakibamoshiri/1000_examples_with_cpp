/*
            Program support Utility
            ***********************

Program Termination:
The following functions manage program termination and resource cleanup
(defined in header <cstdlib>)

    > abort             : causes abnormal program termination (without cleaning up)
    > exit              : causes normal program termination with cleaning up
    > quick_exit        : causes quick program termination without completely cleaning up
    > _Exit             : causes normal program termination without cleaning up
    > atexit            : registers a function to be called on std::exit() invocation
    > at_quick_exit     : registers a function to be called on quick_exit invocation
    > EXIT_SUCCESS      : indicate program execution execution status
    > EXIT_FAILURE      : same as above
*/
/// std::at_quick_exit
//
//  Registers the function pointed to by the 'fucn' to be called
//  on quick program termination (via std::quick_exit)
//  Calling the function form several threads does not include a data
//  race. The implementation shall support the registration of at least
//  32 functions.

#include <iostream>
#include <cstdlib>

int main (){ /* has no example */ }
