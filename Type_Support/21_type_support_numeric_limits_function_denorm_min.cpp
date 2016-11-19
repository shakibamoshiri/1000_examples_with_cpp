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
/// std::numeric_limit::denorm_min
//    Returns the minimum positive subnormal value of the type T,
//    if std::numeric_limits<T>::has_denorm != std::denorm_absent,
//    otherwise returns std::numeric_limits<T>::min(). Only meaningful for floating-point types.


#include <iostream>
#include <limits>
#include <cassert>

int main(){

    // the smallest subnormal value has sign bit = 0, exponent = 0
    // and only the least significant bit of the fraction is 1
    uint32_t denorm_bits = 0x0001;
    float denorm_float = reinterpret_cast<float&>(denorm_bits);
    assert(denorm_float == std::numeric_limits<float>::denorm_min());

}
