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
    parameter list
syntax:
1   attribute ( optional ) dss declarator
2   attribute ( optional ) dss declarator = initializer
3   attribute ( optional ) dss abstract-declarator (optional)
4   attribute ( optional ) dss abstract-declarator (optional) = initializer
5   ...
6   void


*/

#include <iostream>
#include <string>
#include <array>

// declares a named ( formal ) parameter
int f(int a,int *p, int (*(*x)(double))[3]);

// declares a named ( formal ) with a default value
int f(int a=7, int *p=nullptr, int (*(*x)(double))[x]=nullptr);

// declares an unnamed parameter
in f(int,int*, int (*(*)(double))[3]);

// declares an unnamed parameter with a default value
in f(int=4 ,int*=nullptr, int (*(*)(double))[3]=nullptr);

// declares a variadic function, may only appear as the last parameter in the parameter list
int f(const char* fmt, ...);

// indicates that the function takes no parameter
void f(void) equivalnet to void f()
int f(void, int);    // error
int f(const void);   // error
inf f(void*);        // okay

int main(){

}










