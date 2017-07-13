
/* Started on November 14th in 2016 */
/* more examples in github.com/k-five */
/*
            Type Support
            ************

Miscellaneous Transformations (in header <type_traits>
    > aligned_storage           defines the type suitable for use as uninitialized storage for type of given size
    > aligned_union             defines the type suitable for use as uninitialized storage for all given types
    > decay                     applies type transformations as when passing a function argument by value
    > enable_if                 hides a function overload or template specialization based on compile-time boolean
    > conditional               chooses one type of another based on compile-type boolean
    > common_type               deduces the result type of mixed-mode arithmetic expression
    > underlying_type           obtains the underlying integer type for a given enumeration type
    > result_of                 deduces the return type of a function call expression
    > void_t                    void variadic alias template

*/
/// std::common_type
// template<class T...> struct common_type {}
//
// Determines the common type among all type T..., that is the type
// all T... can be implicitly converted to.

#include <iostream>
#include <type_traits>
#include <typeinfo>

template<class T> struct Number { T n; };

template<class T, class U>
    Number<typename std::common_type<T, U>::type>
        operator + (const Number<T>& lhs, const Number<U>& rhs){
            return {lhs.n + rhs.n};
        }


int main(){
    Number<int> i1 = {1}, i2 = {2};
    Number<double> d1 = {2.3}, d2 = {3.5};

    std::cout << "i1 + i2 " << (i1 + i2).n << '\n'          // 3
              << "d1 + d2 " << (d1 + d2).n << '\n'          // 5.8
              << "i1 + d1 " << (i1 + d1).n << '\n'          // 5.3
              << "i2 + d2 " << (i2 + d2).n << std::endl;    // 5.5
}
