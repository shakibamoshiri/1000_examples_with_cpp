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

struct S {
    void f(int);
};
void S::f(int i){
//    [a ,i]{};       // okay
    [&, &i]{};      // error, i preceded by a & when & is the default
    [=, this]{};    // error, this when = is the default
    [i, i]{};       // error, i repeated
}

int main(){
    /*
        Capture List
        The capture-list is a comma-separated list of zero or more capture,
        optionally beginning with the capture-default. The only capture __
        defaults are & ( implicitly catch the odr-used automatic variable and
        'this' by reference ) and = ( implicitly catch the odr-used automatic
        variable and this by value )

        & : capture all by reference
        = : capture all by value

        what is the identifier? it is [] square-bracket

        1   identifier                          : simple by-copy capture
        2   identifier ...                      : by copy capture that is a pack expression
        3   identifier initializer since c++14  : by copy capture with an initializer
        4   & identifier                        : simple by reference capture
        5   & identifier ...                    : by reference capture that is a pack expression
        6   & identifier initializer            : by reference capture with an initializer
        7   this                                : capture for the this pointer

    */
    // If a capture-default is used, no other captures may use the same
    // capture type. Any capture may appear only one.
    //  see struct S above

    // This is used to capture move-only type with a capture such as x = std::move(x)
    int x = 4;
    auto y = [&r = x, x = x+1]() -> int {
        r += 2;
        return x+2;
    }();            // updates ::x to 6 and initializes y to 7
    std::cout<<y;

}

