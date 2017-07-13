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
/// EXIT_SUCCESS
/// EXIT_FAILURE
//  define EXIT_SUCCESS /* implementation defined */
//  define EXIT_FAILURE /* implementation defined */
//
//  The EXIT_SUCCESS and EXIT_FAILURE macros expand into integral
//  expression that can be used as argument to the std::exit function
//  (and therefore, as the values return from the main function) and
//  indicate program execution status.
//
//  EXIT_SUCCESSD   successful execution of a program
//  EXIT_FAILURE    unsuccessful execution of a program

#include <iostream>
#include <cstdlib>

int main (){ /* see the previous examples */ }
