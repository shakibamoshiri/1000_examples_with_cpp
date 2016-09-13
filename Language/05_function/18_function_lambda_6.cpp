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

void f (int, const  int(&)[2] = {} ) {}     // #1
void f (const int&, const int (&)[1]) {}    // #2
void test () {
    const int x = 17;
    auto g1 = [](auto a){ f(x); };          // okay, calls #1, does not capture x
    auto g2 = [=](auto a) {
        int selector[sizeof(a) == 1 ? 1 : 2] = {};
        f(x , selector);                    // okay, is a dependent expression, so capture x
    };
}

// If the body of a lambda odr-uses an entity captured by copy,
// the member of the closure type is accessed. If it is not odr-using
// the entity, tha access is to the original object.
void f(const int*);
void g(){
    const int N = 10;
    [=]{
        int arr[N];     // not an odr-use: refers to to g's const int N
        f(&N);          // odr-use: causes N to be captured ( by copy )
                        // &n is the address of the closure object's member N, not g's N
    }
}

// within the body of a lambda, any use of declare on any variable with automatic
// storage duration is as if it were captured and odr-used, even though decltype
// itself is not an odr-use and no actual capture taken place:
void f3 () {
    float x, &r = x;
    [=]
    {   // x and r are not captured ( appearance in a decltype operand is not an odr-use)
        decltype(x) y1;         // y1 has type float
        decltype((x)) y2 = y1;  // y2 has type const& because this lambda is not mutable and x is an l-value
        decltype(r) r1 = y1;    // r1 has type float& ( transformation not considered )
        decltype((r)) r2 = y2;  // r2 has type float const&
    };
}




int main(){

}

