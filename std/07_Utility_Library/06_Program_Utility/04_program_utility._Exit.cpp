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
/// std::_Exit
//  [[ noreturn ]] void _Exit (int exit_code); since c++11
//
//  Causes normal program termination to occur without
//  completely cleaning the resource.

#include <iostream>
#include <cstdlib>


class Static {
public:
    ~Static (){ std::cout << "~Static destructor\n"; }

}; // the end of the class Static

class Local {
public:
    ~Local (){ std::cout << "~Local destructor\n"; }

}; // the end of the class Local

Static static_variable; // destructor of this object *will* be called

void atexit_handler (){ std::cout << "atexit handler\n"; }

int main() {

    Local local_variable;       // destructor of this object will *not* be called

    // handler will *not* be called
    const int result = std::atexit( atexit_handler );

    if (result != 0){
        std::cerr << "atexit registration failed\n";
        return EXIT_FAILURE;
    }

    std::cout << "test" << std::endl;   // flush form std::endl

    // needs to be here, otherwise nothing will be printed
    std::_Exit( EXIT_FAILURE );
}
