/*

A review if functional library


Function object:
Function objects are objects that specifically have designed to be
used with a syntax similar to that of function. In C++ this is
achieved by defining the member function operator() in their class
like below example:
*/

/// std::mem_fn
//  Converts member function to a function object.

#include <iostream>
#include <functional>

struct int_holder {
    int value__;

    int triple() const {
        return value__ * 3;
    }
};

int main(){

    int_holder five_{ 5 };
    std::cout << five_.triple() << '\n';

    // same as above using the std::mem_fn
    auto triple = std::mem_fn( &int_holder::triple );
    std::cout << triple( five_ ) << '\n';

}

/* output

15
15

Process returned 0 (0x0)   execution time : 0.027 s
Press ENTER to continue.


*/
