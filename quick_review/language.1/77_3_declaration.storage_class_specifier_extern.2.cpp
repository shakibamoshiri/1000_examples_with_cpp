/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// initialization

#include <iostream>
#include <string>
#include "extern.cpp"

/// note:
//  error: a storage class can only be specified for objects and functions
// extern struct S;

extern int S::number;
extern S object;        // S is a type


int main(){

    // storage class specifier - extern

    std::cout << number << '\n';    // okay prints 23

    std::cout << S::number << '\n'; // print 0

    std::cout << object.number << '\n'; // also print 0

    object.number = 33;
    std::cout << object.number << '\n'; // now prints 33

    /// some warning:
    // line |10| warning: type qualifiers ignored on function return type [-Wignored-qualifiers] | extern.cpp
    // line |24| warning: cannot explicitly declare member ‘int S::number’ to have extern linkage [-Wpedantic] |  tmep.cpp
}



/* output:


*/
