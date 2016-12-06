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
/// std::numeric_limit::quiet_NaN
//    Returns the special value "quiet not-a-number", as represented by the floating-point
//    type T. Only meaningful if std::numeric_limits<T>::has_quiet_NaN == true. In IEEE 754,
//    the most common binary representation of floating-point numbers, any value with all bits
//    of the exponent set and at least one bit of the fraction set represents a NaN. It is
//    implementation-defined which values of the fraction represent quiet or signaling NaNs,
//    and whether the sign bit is meaningful.


#include <cmath>
#include <limits>
#include <iostream>


int main(){
    std::cout << std::numeric_limits<double>::quiet_NaN() << ' '
              << std::numeric_limits<double>::signaling_NaN() << ' '
              << std::acos(2) << ' '
              << std::tgamma(-1) << ' '
              << std::log(-1) << ' '
              << std::sqrt(-1) << ' '
              << 0 / 0.0 << '\n';

    std::cout << "NaN == NaN? " << std::boolalpha
              << ( std::numeric_limits<double>::quiet_NaN()
                   == std::numeric_limits<double>::quiet_NaN() ) << '\n';
}
