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
    int a=10;
    int b=-10;
    // it is correct but no need both capture list and parameter-list
    auto one = [&a,&b](int a,int b) mutable { ++a; ++b; };
    one(a, b);
    std::cout<<a<<' '<<b<<std::endl;



    a=10, b=10;
    // needs a parameter-list to modify
    auto two = [](int a,int b) mutable { ++a; ++b; };
    two(a,b);
    std::cout<<a<<' '<<b<<std::endl;



    a=10, b=-10;
    // when it is captured, no need to parameter-list
    auto three = [&a, &b]() mutable {++a; ++b;};
    three();
    std::cout<<a<<' '<<b<<std::endl;



    a=10, b=-10;
    // no need parentheses
    auto four = [&a, &b]{ ++a; ++b; };
    four();
    std::cout<<a<<' '<<b<<std::endl;


    a=10, b=-10;
    //  using return, returning type is int and must be defined in body ( I mean return a-b )
    int c = [a, b]() -> int { return a-b;}();
    std::cout<<c<<std::endl;

}

