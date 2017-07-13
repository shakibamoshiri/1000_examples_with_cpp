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
    /* A generic captureless lambda has user-defined conversion function template
       with the same invented template parameter list as the function-call operator
       template. If the return type is empty or auto, it is obtained by return type
       declaration on the function template specialization, which, in turn, is obtained
       by template argument declaration for conversion function template
    */
    // declaration function is not allowed in main function
    // but it is some sample

    void f1 ( int (*)(int) ){}
    void f2 (char (*)(int) ){}
    void h  ( int (*)(int) ){}  // #1
    void h  (char (*)(int) ){}  // #2
    auto glambda = [] (auto a){return a;};

    f1 ( glambda ): // okay
    f2 ( glambda ); // error, not convertible
    h  ( glambda ); // okay: calls #1 since #2 is not convertible

    int& (*pfi)(int*) = [](auto* a)-> auto& { return *a;};  // okay
}

