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
///  std::is_bind_expression

#include <iostream>
#include <functional>
#include <type_traits>

struct MyBind {
    typedef int result_type;
    int operator () (int t1, int t2){ return (t1 + t2); }
};

namespace std {
    template<>
    struct is_bind_expression< MyBind > : public true_type {};
}

int f (int n1, int n2){ return (n1 + n2); }

int main() {

    // as if bind( f, bind( MyBind::operator(), _1, _2) 2)
    auto b1 = std::bind( f, MyBind(), 2 );

    std::cout << "adding 2 to the sum of 10 and 11 gives: "
              << b1( 10, 11 ) << std::endl;

}


/* output for me:

adding 2 to the sum of 10 and 11 gives: 23

it means it first adds 10 to 11 => 21
then add 2 to 21 and the result is 23
pay attention to above:
    std::bind( f, MyBind(), 2). here 2 is added to

*/


