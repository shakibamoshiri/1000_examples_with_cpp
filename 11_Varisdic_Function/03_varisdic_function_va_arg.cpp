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
/// va_arg : T va_arg (va_list ap, T)
//  The va_args macro expends to an expression of type T that corresponds
//  to the next parameter from the va_list ap.
//

#include <iostream>
#include <cstdarg>
#include <cmath>

double stddev (int count, ...){

    double sum = 0;
    double sum_sq = 0;

    va_list args;
    va_start (args, count);

    for (int i = 0; i < count; ++i){
        double num = va_arg (args, double);
        sum += num;
        sum_sq += num * num;
    }

    va_end (args);

    return std::sqrt( sum_sq / count - (sum / count) * (sum / count));

} // the end of stddev

int main(){

    std::cout << stddev( 4,     // the number of value that we want to calculate
                        25.0,   // argument 1
                        27.3,   // argument 2
                        26.9,   // argument 3
                        25.7)   // argument 4
                        << std::endl;


}

