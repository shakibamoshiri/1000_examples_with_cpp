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
/// va_list : it is a typedef name
//  va_list is a complete object type suitable for holding the
//  information needed by the macros va_start, va_copy, va_arg an va_end.

#include <iostream>
#include <cstdarg>
#include <cmath>

int main() { /* had no example. You can see the previous example */ }
