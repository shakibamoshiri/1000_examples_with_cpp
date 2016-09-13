/**

/// Expression
/// Implicit Conversions
/// function pointer conversion

**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"

int main(){

    /// A prvalue of type pointer to noexcept function can be converted to prvalue pointer to function.
    /// A prvalue of type pointer to noexpect member function can be converted to prvalue pointer to member function.

    void (*p)() throw(int);

    /// Error: cannot convert to pointer to no-except function.
    void (**pp)() noexcept = &p;

    /// typedef "void (*p)() to p
    struct S {typedef void(*p)(); operator p(); };

    /// Error: cannot convert to pointer to no-except function.
    void (*q)() noexcept = S();
}













