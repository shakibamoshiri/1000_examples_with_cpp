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
/// std::numeric_limit::round_error
//    Returns the largest possible rounding error in ULPs (units in the last place)
//    as defined by ISO 10967, which can vary from 0.5 (rounding to the nearest digit)
//    to 1.0 (rounding to zero or to infinity). It is only meaningful if
//    std::numeric_limits<T>::is_integer == false.



#include <limits>
#include <iostream>


int main(){
    std::cout << std::numeric_limits<float>::round_error() * 1.11 << std::endl;     // okay It is done
    std::cout << std::numeric_limits<double>::round_error() * 3.35 << std::endl;    // okay it is done
    std::cout << std::numeric_limits<int>::round_error() * 1.11 << std::endl;       // for int type is false. It outputs 0
}
