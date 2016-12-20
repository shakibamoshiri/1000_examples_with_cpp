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
///  std::placeholders::_1, std::placeholders::_2, ..., std::placeholders::_N

#include <iostream>
#include <functional>
#include <string>

void goodbye (const std::string& str){ std::cout << "goodbye " << str << '\n'; }


class Object {
public:
    void hello (const std::string& str){ std::cout << "hello " << str << '\n'; }
};


int main() {

    typedef std::function< void (const std::string& ) > ExampleFunction;

    Object instance;

    std::string str("world");

    ExampleFunction f = std::bind( &Object::hello,          // the address of function member
                                  &instance,                // the object of class Object
                                  std::placeholders::_1);   // first argument

    // equivalent to instance.hello( str );
    f( str );

    f = std::bind( &goodbye, std::placeholders::_1 );

    // equivalent to goodbye( str );
    f( str );

}


/* output for me:

hello world
goodbye world


*/


