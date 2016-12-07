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
/// va_start: void va_start (va_list ap, parm_n )
//
// The va_start macro enabler access to the variable arguments following
// the named argument 'parm_n' (parameter).
// va_start should be invoked with an instance to a valid va_list object
// ap before any calls to va_arg.
// If 'parm_n' is declared with reference type or with a type not compatible
// with type that results form default argument promotions, the behavior is undefined.
//
/// NOTE:
// va_start is required to support 'pram_n' with overloaded operator &

#include <iostream>
#include <cstdarg>


int add_nums (int count, ...){

    int result = 0;

    va_list args;               // declare args
    va_start( args, count );

    for (int i = 0; i < count; ++i) result += va_arg( args, int );

    va_end( args );

    return result;

} // the end of add_nums

int main(){

    std::cout << add_nums(1, 2, 3, 4, 5, 6) << '\n';
    // If you think that the output of this function is 19, you completely wrong :)
    //
    // At first looking, you think, okay it would be something like this:
    // 1 + 2 + 3 + 4 + 5 + 6 and of course the answer is: 19
    // but unfortunately the output is 1
    // why? see below:


    std::cout << add_nums(4, 25, 25, 50, 50) << '\n';
    // in fact, the first argument is the number of the others arguments
    // that you want to calculate
    // so here, first '4' means we have 4 number
    // and those 4 numbers are:
    // 25 + 25 + 50 + 50
    // and the output will be: 150


}
