/*
            Function Object
            ***************

2. Bind
    2.1 bind
        The function template bind generates a call wrapper for f(argument)
        Calling this wrapper is equivalent to invoking of with some of its
        arguments bound to args(argument).

        return value:
        A function object of unspecified type T, for which std::is_bind_expression<T>::value == true.
        for more detail see the man website.

    --------------------------------------------
    2.2 is_bind_expression
        If T is type produced by a call to std::bind, this template is derived
        from std::true_type. For any other type, this template is derived from
        std::false_type.

        helper variable template
        template<class T>
        constexpr bool is_bind_expression_v = is_bind_expression<T>::value

    --------------------------------------------
    2.3 is_placeholder
        If T is type of a standard placeholder(_1, _2, ...) then this template is derived
        from std::integral_constant<int, 1>, std::integral_constant<int, 2> ... respectively
        If T is not a standard placeholder type, this template is derived from std::integral_constant<int, 0>.

    --------------------------------------------
    2.4 placeholder
        The std::placeholders namespace contains the placeholder object
        (_1, ..., _N) where N is an implementation defined maximum number.
        When used as an argument in a std::bind expression, the placeholder
        objects ar stored in the generated function object, and when that
        function object is invoked with unbound arguments, each placeholder _N
        is replaced by the corresponding Nth unbound argument.



*/
///  std::bind

#include <iostream>
#include <functional>


void func( int n1, int n2, int n3, const int& n4, int n5 ){
    std::cout << n1 << ' '
              << n2 << ' '
              << n3 << ' '
              << n4 << ' '
              << n5 << std::endl;
}

int g( int n1 ){ return n1; }



int main (){
    using namespace std::placeholders;  // for _1, _2, _3, ....

    // demonstrates argument recording and pass-by-reference
    int n = 7;

    /* (_1, and _2 are from std::placeholders, and represent future
        argument that will passed to f1 */
    auto f1 = std::bind( func, _2, _1, 42, std::cref( n ), n ); // the n == 7 above
    n = 10;
    f1( 1, 2, 1001 ); // output is: 2 1 42 10 7
    // 2 -> _1
    // 1 -> _2
    // 42 -> in the bind function forth argument
    // 10 -> &n that it was pass by reference
    // 7 -> n   that it was passed by value

    /// nested bind  subexpression share the placeholders
    auto f2 = std::bind( func,              // func function
                        _3,                 // first argument of func is third placeholder
                        std::bind( g, 3),   // second argument of func is the return value if function g
                        _3,                 // third argument again is third placeholder
                        4,                  // forth argument directly is 4
                        5);                 // fifth argument directly is 5 as well
    f2( 10, 11, 12);        // 12 3 12 4 5
    // _3 ->        12
    // g(3) returns 3
    // _3 ->        12 again
    // empty ->     4
    // empty ->     5
}

/* output for me:



*/


