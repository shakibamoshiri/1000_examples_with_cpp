/*
            Varisdic Function
            *****************

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
/// std::quick_exit
//  [[ noreturn ]] void quick_exit( int exit_code ); since c++11
//
//  Causes normal program termination to occur without completely
//  cleaning up the resource.

#include <iostream>
#include <cstdlib>

int main() { /* has no example */ }
