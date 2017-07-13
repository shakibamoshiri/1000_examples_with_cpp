
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
/// std::result_of
//
// Deduced the return type of a function call expression at compile time.

#include <iostream>
#include <type_traits>
#include <typeinfo>

struct S {
    double operator() (char, int&);
    float  operator() (int) { return 1.0; }
};

template<class T>
typename std::result_of<T(int)>::type
f (T& t){
    std::cout << "overload of f for callable T\n";
    return (0);
}

template<class T, class U> int f(U u) {
    std::cout << "overload of f for non-callable T\n";
    return u;
}

int main(){

    // the result of invoking S with char and int& argument is double
    std::result_of<S(char,int&)>::type d = 3.14;    // d has type double
    static_assert(std::is_same<decltype(d), double>::value, "");

    // the result in invoking S with int argument in float
    std::result_of<S(int)>::type x = 3.15;      //  f function has type float

    // result_of can be used with a pointer to member function as follows:
    struct C { double func(char,int&); };
    std::result_of<decltype(&C::func)(C,char,int&)>::type g = 3.14;
    static_assert(std::is_same<decltype(g),double>::value, "" );

    f<C>(1);    // fail to compile in c++11 , calls the non-callable overload in c++14
    // output:
    // overload of f for non-callable T

}
