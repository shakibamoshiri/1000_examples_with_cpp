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
#include <memory>



struct S {
    int data = 10;
    void sum( int n1, int n2 ){ std::cout << (n1 + n2) << '\n'; }
};



int main (){
    using namespace std::placeholders;  // for _1, _2, _3, ....

    // bind to a member function
    S s0;

    auto f1 = std::bind( &S::sum, &s0, 95, _1 );
    f1( 5 );    // output is 100
                // because the first argument is 95 and 95 + 5 = 100
                // and it preserved even if you put two parameter

    f1( 3, 5 ); // output is 98 which it means 95 adds to 3 and the result is 98


    // bind to member data
    auto f2 = std::bind( &S::data, _1 );
    std::cout << f2( s0 ) << std::endl;     // output is: 10

    // smart pointer can be used  to call member of the reference objects, too
    std::cout << f2( std::make_shared< S >( s0 ) )<< '\n'                   // output is 10
              << f2( std::unique_ptr< S >( new S( s0 ) ) ) << std::endl;    // output is 10

}

/* output for me:

100
98
10
10
10

*/


