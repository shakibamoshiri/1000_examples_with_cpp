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
    int a=1, b=1, c=1;
    auto m1 = [a, &b, &c]() mutable {
        auto m2 = [a, b, &c]() mutable {
            std::cout<<"before m2: "<<a<<' '<<b<<' '<<c<<std::endl;
            a=4; b=4; c=4;  // only modifies c, since it capture by reference
            std::cout<<"after m2: "<<a<<' '<<b<<' '<<c<<std::endl;
        };
        m2();
        a=3; b=3; c=3;
        std::cout<<"inside m1: "<<a<<' '<<b<<' '<<c<<std::endl;
    };

    a=2; b=2; c=2;
    m1();
    std::cout<<a<<' '<<b<<' '<<c<<std::endl;
}

