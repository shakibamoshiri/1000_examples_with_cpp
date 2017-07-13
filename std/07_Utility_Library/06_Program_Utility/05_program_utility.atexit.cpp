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
/// std::atexit
//  extern "C"   int atexit( void (*func)() );
//  extern "C++" int atexit( void (*func)() );
//
//  Registers the function pointed to by func to be called on normal
//  program termination (via std::exit() or returning from the cpp/language/main function)

#include <iostream>
#include <cstdlib>


void atexit_handler_1 (){ std::cout << "at exit #1\n"; }

void atexit_handler_2 (){ std::cout << "at exit #2\n"; }

int main (){
    const int result_1 = std::atexit( atexit_handler_1 );
    const int result_2 = std::atexit( atexit_handler_2) ;

    if ((result_1 != 0) or (result_2 != 0)) { // or == ||
        std::cerr << "Registration failed\n";
        return EXIT_FAILURE;
    }

    std::cout << "returning from main\n";
    return EXIT_SUCCESS;
}
