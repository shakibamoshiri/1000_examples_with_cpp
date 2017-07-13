
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
/// std::decay
// Applies l-value-to-r-value, array-to-pointer, and function-to-pointer
// implicit conversions to the type T, removes cv-qualifiers and define
// resulting type as the member typedef type.
// This is the type conversion applied to all function arguments when passed by value.


#include <iostream>
#include <type_traits>


template<typename T,typename U>
struct decay_equiv : std::is_same<typename std::decay<T>::type, U>::type {};


int main(){
    std::boolalpha( std::cout );

    std::cout << decay_equiv<int, int>::value << '\n';              // true
    std::cout << decay_equiv<int&, int>::value << '\n';             // true
    std::cout << decay_equiv<int&&, int>::value << '\n';            // true
    std::cout << decay_equiv<const int&, int>::value << '\n';       // true
    std::cout << decay_equiv<int[2], int*>::value << '\n';          // true
    std::cout << decay_equiv<int(int),int(*)(int)>::value << '\n';  // true
}
