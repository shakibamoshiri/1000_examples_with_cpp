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
/// va_copy : void va_copy( va_list dest, va_list src )
//
//  The va_copy macro copies src to dest.
//  va_end should be called on dest before the function returns
//  or any subsequent re-initialization of dest (via calls to va_start or va_copy).

#include <iostream>
#include <cstdarg>
#include <cmath>

double stddev (int count, ...){

    double sum = 0;

    va_list arg1;
    va_start (arg1, count);
    va_list arg2;
    va_copy (arg2, arg1);

    for (int i = 0; i < count; ++i){
        double num = va_arg (arg1, double);
        sum += num;
    }

    va_end (arg1);
    double mean = sum / count;

    double sum_sq_diff = 0;

    for (int i = 0; i < count; ++i){
        double num = va_arg (arg2, double);
        sum_sq_diff += (num - mean) * (num - mean);
    }

    va_end (arg2);

    return std::sqrt( sum_sq_diff / count);

} // the end of the: double stddev


int main() {

    std::cout << stddev( 4,     // the number of value that we want to calculate
                    25.0,   // argument 1
                    27.3,   // argument 2
                    26.9,   // argument 3
                    25.7)   // argument 4
                    << std::endl;

}
