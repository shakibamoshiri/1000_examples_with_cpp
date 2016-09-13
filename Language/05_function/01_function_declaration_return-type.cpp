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
    // declares an int, an int*, a function, and a pointer to a function
    int a = 1, *p = NULL, f(), (*pf)();

    /* return type deduction since c++14 */
    int x = 1;
    auto f() { return x;};          // return type is int
    const auto& f(){ return x;};    // return type is const int&

    // if the return type is 'decltype(auto)' the return type is as what
    // would be obtained if the expression used in the return statement
    // were wrapped in decltype
    int d = 1;
    decltype(auto) f() { return d; };       // return type is int, same as decltype (d);
    decltype(auto) f() { return (d);};      // return is int&, same as decltype ((d))

    // if there are multiple return statement, they must all deduce to the same type
    auto f(bool val){
        if (val) return 123;        // deduces return type is int
        else     return 3.33f;      // deduces return type is float, error
    }

    auto sum (int i){
        if (i==1)
            return a;           // sum's return type is int
        else
            return sum(i-1);    // okay, sum's return type is already known
    }
}










