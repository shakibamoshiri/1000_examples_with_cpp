/*
Function:
    declaring function
    default argument
    variadic argument
    lambda function
    operator overloading
    address of overloading function
***************************************
    Declaring Function
**********************
A function declaration introduced the function name and its type.
A function definition associates the function name/type with the
function body.


*/

#include <iostream>
#include <string>
#include <array>

int main(){
    // if the return statement uses a brace-list-initialization, declaration is not allowed
    auto func() { return {1,2,3}; }     // error

    // virtual function cannot use return type-deduction
    struct F {
        virtual auto f() { return 2;} // error
    };

    // if a function used return type deduction, it cannot be redeclared using the
    // type that it deduced to, or another kind of return type deduction even if
    // deduction to the same type
    auto f();               // declared, not yet defined
    auto f(){ return 53;}   // defined, return type is int
    int f();                // error, cannot use the deduced type with f function that before declared with auto
    decltype(auto) f();     // error, different kind of deduction
    auto f();               // redeclared, okay

    // function template can use return type deduction
    template<class T> auto f(T t) {return t;}       // okay
    typedef decltype(f(1)) fint_t;                  // instantiation f<int> to deduce return type
    template<<class T> auto f(T* t) {return *t;}
    void g() int (*p)(int*) = &f;}                  // instantiation both fs to determine return types,
                                                    // chooses second template overload

    // specializations of function templates that use return type deduction must be
    // use the same return type placeholders
    template<typename T> auto g(T t) {return t;};       // okay #1
    template auto g(int);                               // okay, return type is int
    template char g(char);                              // error, no matching template

    template<> auto g(double);                          // okay, forward declaration with unknown return type
    template<typename T> T g(T t){return t;}            // okay, not equivalent to #1
    template char g(char);                              // okay, now there is matching template
    template auto g(float);                             // still matches #1
}










