/**
/// decltype specifier
///
Inspects the declared  type of an entity or queries the type and value category of an expression.
Syntax:
decltype ( entity )
decltype ( expression )

Explanation
1)  If the argument is an un-parenthesizes id-expression or an un-parenthesized
    class member access, then decltype yields the type of the entity named by
    this expression. If there is no such entity, or if the argument names a set
    of overloaded functions, the program is ill-formed.
2)  If the argument is any other of expression if type T, and
    - if the value category of expression is x-value, then decltype yields T&&
    - if the value category of expression is l-value, then decltype yields T&
    - if the value category of expression is p-value, then decltype yields T

NOTE:
that if the name of an object is parenthesized, it is treated as an
ordinary l-value expression, thus decltype(x) and decltype((x)) are
often different types.

**/
#include <iostream>
#include <string>
#include <stdexcept>

struct A { double x;};
const A* a = new A {0};

decltype(a->x) x3;          // type of x3 is double ( declared type )
decltype((a->x)) x4 = x3;   // type of x4 is const double& (l-value expression )

template<typename T,typename U>
auto add (T t, U u) -> decltype(t+u);   // return type depends on template parameters

int main(){
    int i = 33;
    decltype(i) j = i*3;
    std::cout<<"i = "<<i<<", "
             <<"j = "<<j<<std::endl;

    auto f = [](int a,int b)->int {
        return a*b;
    };

    decltype(f) f2 = f;     // the type of a lambda function is unique and unnamed

    i = f(2,2);
    j = f2(3,3);
    std::cout<<"i = "<<i<<", "
             <<"j = "<<j<<std::endl;


}











