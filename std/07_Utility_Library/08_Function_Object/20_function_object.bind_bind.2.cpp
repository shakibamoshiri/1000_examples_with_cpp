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
#include <random>



int main (){
    using namespace std::placeholders;  // for _1, _2, _3, ....

    // common use case: binding a RNG with a distribution
    std::default_random_engine e;
    std::uniform_int_distribution <> d (0, 10);
    std::function< int () > rnd = std::bind( d, e );    // a copy of e is stored in rnd

    for (int n = 0; n < 10; ++n ) std::cout << rnd() << ' '; // output: 0 1 8 5 5 2 0 7 7 10


}

/* output for me:



*/


