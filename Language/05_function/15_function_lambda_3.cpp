/*
Function:
    declaring function
    default argument
    variadic argument
*   lambda function
    operator overloading
    address of overloading function
***************************************
     lambda function
**********************
Constructs a closure: an unnamed function object capable of capturing variables in scope
oxford
closure: the situation when a factory, school, hospital, shuts permanently.( temporary )
syntax:
1   [ capture-list ]( parameter ) mutable ( optional ) exception attribute -> return { body }
2   [ capture-list ]( parameter ) -> return { body }
3   [ capture-list ]( parameter ) { body }
4   [ capture-list ]{ body }

1   full declaration.
2   declaration of a constant lambda: the object is captured by copy cannot modified
3   Omitted trailing-return-type: the return type of the closure's operator() determined
    according to the following rules.
    ...

capture list:
    - [a, &b]   where a is captured by value and b is captured by reference
    - [this ]   captures this 'this' pointer by value
    - [&]       captures all automatic variable odr-used in the body of the lambda by reference
    - [=]       captures all automatic variable odr-used in the body of the lambda by value
    - []        captures nothing



*/

#include <iostream>
#include <string>
#include <array>

int main(){
    /* closure type :: operator () (parameter)

    return operator()( parameter ) const { body }   ... the keyword mutable was not used
    return operator()( parameter ) { body }         ... the keyword mutable was used
    template<template-parameter>
    return operator()( parameter ) { body }         ... since c++14, generic lambda
    */
    // generic lambda, operator() is a template with two parameter
    auto glambda = [](auto a, auto&& b){return a<b;};
    bool b = glambda(3,4);
    std::cout<<b<<std::endl;

    // generic lambda, operator() is a template with one parameter
    auto vglambda = [](auto printer ){
        return [=](auto&&... ts)    // generic lambda, ts is a parameter pack
        {
            printer(std::forward<decltype(ts)>(ts)...);
            return [=] { printer(ts...); };
        };
    };
    auto p = vglambda([](auto v1, auto v2, auto v3){std::cout<<v1<<' '<<v2<<' '<<v3;});
    auto q = p(1, 'a', 3.15);
    q();

    // note: closureType's operator() cannot be explicitly instantiated or explicitly specialized

    struct X {
        int x, y;
        int operator() (int);
        void f(){
            // the context of the following lambda is the member function X::f
            [=]()->int{
                return operator()(this->x + y); // x::operator()(this->x + (*this).y), this has a type X*
            };
        }
    };
    // note: ClosureType's operator() cannot be named in a friend declaration
}

