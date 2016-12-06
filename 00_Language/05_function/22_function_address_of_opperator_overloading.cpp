/*
Function:
    declaring function
    default argument
    variadic argument
    lambda function
    operator overloading            // skipping
*   address of overloading function
***************************************
     address of overloading function
**********************
Besides function-call-expression, where overload resolution takes place,
the name of an overloaded function may appear in the following 7 contexts:
1   initializer in a declaration of an object or reference
2   one the right-hand-side of an assignment expression
3   as a function call argument
4   as a user-defined operator assignment
5   the return statement
6   explicit cast or static_cast argument
7   non-type template argument

*/

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

int f(int) { return 1;}
int f(double) {return 2;}

void g( int(&f1)(int), int(*f2)(double)){}

template< int(*F)(int) >
struct Fptr_t {};

struct Foo {
    int mf(int){return 3;}
    int mf(double){return 4;}
};

// return value
int (*(foo)(void))(int){
    return f;  // selects int f(int);
}

int main(){

    // initialization:

    int (*pf)(double) = f;  // selects int f (double)
    int (&rf)(int) = f;     // selects int f (int)

    int (Foo::* pmf)(int);  // selects int mf (int)

    // assignment

    pf = nullptr;
    pf = &f;                // selects int f (double)

    // function argument

    g(f,f);                  // first argument is int f (int), second is int f (double)

    // cast

    std::string str = "Example";
    std::transform(str.begin(), str.end(), str.begin(),
                   static_cast<int(*)(int)>(std::toupper)); // selects int toupper (int)
    std::cout<<str<<std::endl;


    // template argument
    Fptr_t<f> t;    // selects int f (int)
}

