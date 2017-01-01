/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Numeric Limits (defined in header <limits>)
    > umeric_limits                     provide an interface to query properties of all fundamental numeric types (class  template)
    Template parameters
    T 	- 	a type to retrieve numeric properties for
Member functions
    min                 returns the smallest finite value of the given type
    lowest              returns the lowest finite value of the given type
    max                 returns the largest finite value of the given type
    epsilon             returns the difference between 1.0 and the next representable value of the given floating-point type
    round_error         returns the maximum rounding error of the given floating-point type
    infinity            returns the positive infinity value of the given floating-point type
    quiet_NaN           returns a quiet NaN value of the given floating-point type
    signaling_NaN       returns a signaling NaN value of the given floating-point type
    denorm_min          returns the smallest positive subnormal value of the given floating-point type
*/
/// std::numeric_limit::signaling_NaN
//    Returns the special value "signaling not-a-number", as represented by the floating-point
//    type T. Only meaningful if std::numeric_limits<T>::has_signaling_NaN == true. In IEEE 754,
//    the most common binary representation of floating-point numbers, any value with all bits
//    of the exponent set and at least one bit of the fraction set represents a NaN. It is
//    implementation-defined which values of the fraction represent quiet or signaling NaNs,
//    and whether the sign bit is meaningful.


#include <iostream>
#include <limits>
#include <cfenv>
#pragma STDC_FENV_ACCESS on

void show_fe_exceptions(){

    int n = std::fetestexcept(FE_ALL_EXCEPT);

    if(n & FE_INVALID) std::cout << "FE_INVALID is raised\n";
    else if(n == 0)    std::cout << "no exceptions are raised\n";

    std::feclearexcept(FE_ALL_EXCEPT);
}

int main(){

    double snan = std::numeric_limits<double>::signaling_NaN();
    std::cout << "After sNaN was obtained ";
    show_fe_exceptions();

    double qnan = snan * 2.0;
    std::cout << "After sNaN was multiplied by 2 ";
    show_fe_exceptions();

    double qnan2 = qnan * 2.0;
    std::cout << "After the quieted NaN was multiplied by 2 ";
    show_fe_exceptions();

    std::cout << "The result is " << qnan2 << '\n';
}
