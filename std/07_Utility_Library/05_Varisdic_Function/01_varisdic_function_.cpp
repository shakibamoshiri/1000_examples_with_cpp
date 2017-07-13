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

#include <iostream>
#include <cstdarg>


void user_printf (const char* fmt, ...){

    va_list args;
    va_start( args, fmt );

    while (*fmt != '\0'){

        if (*fmt == 'd'){
            int i = va_arg( args, int );
            std::cout << i << '\n';
        } else if (*fmt == 'c'){
            // note automatic conversion to integral type
            int c = va_arg( args, int );
            std::cout << static_cast<char>(c) << '\n';
        } else if (*fmt == 'f'){
            double d = va_arg( args, double);
            std::cout << d << '\n';
        }

        ++fmt;
    }
    va_end( args );
} // the end of user_printf

int main(){

    user_printf("fdfcd",
                3.44,   // double
                100,    // decimal
                0.33,   // double
                'a',    // char
                10);    // decimal

}
