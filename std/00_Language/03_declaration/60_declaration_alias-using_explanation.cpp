/**
Type alias, alias template (since c++11)
Type alias is name that refers to previously defined type ( similar to typedef )
Alias template is a name that refers to a family of type.

Syntax:
Alias declaration are declarations with the following syntax:
1. using identifier attribute ( optional ) type-id;

2. template<template parameter list>
using identifier attribute ( optional ) = type-id;

**/

#include <iostream>
#include <string>

int i(int){return 9;}
float f(float){return 3.33;}

int main(){

    /*
        1)  A type alias declaration introduced a name which can be used an a synonym for
        the type denoted by type-id. It does not introduced a new type and it cannot change
        the meaning of an existing type name. There is no difference between a type alias
        declaration and 'typedef' declaration. This declaration may appear i block scope,
        class scope, or namespace type.
    */
    // typedef style:
    typedef int (*pointer2int)(int);
    pointer2int pi = i;
    std::cout<<pi(0)<<std::endl;


    // using style:
    using pointer2float = float (*)(float);
    pointer2float pf = f;
    std::cout<<pf(0.0)<<std::endl;

    /*
        2)  An alias template is a template which, when specialized, is equivalent to the result
        of sub-situation the template arguments of the alias template for the template parameter
        in the type-id
    */

    template <typename T> struct Alloc{};
    template <typname T> using Vec = vector <T, Alloc<T>>;  // type-id is vector<T, Alloc<T>>
    Vec<int> v;                                             // Vec<int> is the same as vector<int, Alloc<int>>

    // the type produced when specializing an alias template is not
    // allowed to directly or indirectly make use of its own type.

    template<class T> struct A;
    template<class T> using B = typename A<T>::U;   // type-id is A<T>::U
    template<class T> struct A{
        typedef B<T> U;
    };
    B<short> b; // error, B<short> uses its own type via A<short>::U

    // Alias template are never deduced by template argument deduction when
    // a template template parameter.


}









