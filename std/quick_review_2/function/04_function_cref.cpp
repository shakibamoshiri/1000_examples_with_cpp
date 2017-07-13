/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::cref( or reference_wrapper )
//  constructs a reference_wrapper to const.

#include <iostream>
#include <functional>



int main(){

    int integer( 10 );

    auto ref_to_integer = std::cref( integer );

    ++integer;

    std::cout << ref_to_integer << '\n';

}

/* output

11

Process returned 0 (0x0)   execution time : 0.026 s
Press ENTER to continue.


*/
