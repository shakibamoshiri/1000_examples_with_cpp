/*
            Varisdic Function
            *****************

Variadic Function:
Variadic functions are functions (e.g. std::printf) which take a variable
number of arguments.

    To declare a variadic function, an ellipsis is used as the last parameter,
    e.g. int printf (const char*, ...);
    See Variadic arguments for additional detail on the syntax, automatic
    argument conversions and the alternatives.
    To access the variadic arguments form the function body, the following
    library facilities are provided:
    (defined in header <cstdarg>)

    > va_start  : enable access to variadic function arguments
    > va_arg    : accesses the next variadic function argument
    > va_copy   : makes a copy fo the variadic function arguments
    > va_end    : ends traversal of the variadic function arguments
    > va_list   : holds the information needed by va_start, va_arg, va_end, and va_copy
*/
/// va_end : void va_end (va_list ap)
//  The va_end macro preforms cleanup for an 'ap' object initialized
//  by a call to va_start or va_copy.
//  va_end may modify 'ap' so that it is no longer unable.

#include <iostream>
#include <cstdarg>
#include <cmath>

int main() { /* had no example. You can see the previous example */ }
