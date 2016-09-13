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
#include <vector>
#include <functional>
#include <algorithm>


int main(){

    /*
    this example shows how to pass a lambda to a generic algorithm:
    how objects resulting from a lambda declaration can be stored
    in std::function object.
    */
    std::vector<int> c = {1,2,3,4,5,6,7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n){return n<x;}), c.end());

    std::cout<<"c: ";
    std::for_each(c.begin(), c.end(), [](int i){std::cout<<i<<' ';});
    std::cout<<std::endl;

    // the type of a closure cannot be named, but can be inferred with auto
    auto func1 = [](int i){return i+4;};
    std::cout<<"func1: "<<func1(6)<<std::endl;

    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) {return i+4;};
    std::cout<<"func2: "<<func2(6)<<std::endl;
}

