/*
Exception:
    01
    02 try-block
    03 function-try-block
    04 noexcept specifier ( since c++11 )
    05 noexcept operator  ( since c++11 )
    06 dynamic exception specifier

    For More Detail Read Main Site = f m d r m s
*/
#include <iostream>
#include <exception>
#include <vector>
/// 03 Function Try-block
// Establishes an exception handler around the body of a function
//
// syntax:
// The function-try block is one of the alternative syntax forms form function
// -body, which is a part of function definition.
// try constructor-initializer (optional) compound-statement handler-sequence
//
// A function-try-block a associate a sequence of catch clauses with the entire
// function body, and with the member initializer list ( if used in a constructor )
// as well.
//
//
//
// NOTEs:
// The primary purpose of function-try-block is to log or or modify, and then rethrow
// the exceptions thrown from the member initializer list in a constructor. They are
// rarely used with destructor or with regular function.
//
// The return statement is not allowed in any catch-clause of a function-try-block
// used on a constructor or a destructor accesses a base ro a non-static member of
// the object.
//
// Function-try-block does not catch the exceptions thrown by the copy / move constructor
// and the destructor of the function parameters passed by value: those exceptions are
// thrown in context of the caller.
//
// The scope and lifetime of the function parameter ( but not any object declared in the
// in the function itself) extend to the end of the handler-sequence.
int f(int n = 2 ) try {

    int m = 20; // m is 20

    ++n;        // new n is 3

    throw n;    // throw int (3)

} catch (...) {

    ++m;        // compile error: ‘m’ was not declared in this scope
                // but not any object declared in the  in the function itself

    ++n;

    if ( n==4 )
        return n;
}

int main(){
    std::cout<<f();
}
