/*
            Error Handling
            **************

4.  Assertion
        > static_assertion  : performs compile-time assertion checking
        > assert            : aborts the program if the user-specified condition is not true. May be disabled for release builds

*/

/// assert
// The definition of the macro assert depends on another macro
// NDEBUG, which is not defined by the standard library.
//
/// in header cassert
/*
    ifdef NDEBUG
    #define assert(condition) ((void)0)
    #else
    #define assert(condition) // implementation defined
    #endif

*/
// If NDEBUG is defined as a macro name at the point in the source
// code where <cassert> in included, then assert does nothing.

#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

int main(){

    assert( 2 + 2 == 4 );
    std::cout << "execution continues past the first assert" << std::endl;

    assert( 2 + 2 == 5 );
    std::cout << "execution continues past the second assert" << std::endl;

}
