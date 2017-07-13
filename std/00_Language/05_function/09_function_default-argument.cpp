/*
Function:
    declaring function
*   default argument
    variadic argument
    lambda function
    operator overloading
    address of overloading function
***************************************
     default argument
**********************
Allowed a function to be called without providing one or more trailing argument.

void print ( int a = 3 , int b = 5 );

print (1,1);    calls print (1,1)
print (1);      calls print (1,5)
print ();       calls print (3,5)

Default arguments are only allowed in the parameter lists of function declaration
and Lambda-expressions. ( since c++14 ) and are not allowed in the declaration of
pointer to function, reference to function, or in typedef declaration. Template
parameter lists are similar syntax for their default template argument.

*/

#include <iostream>
#include <string>
#include <array>

void f(int, int);       // #1
void f(int, int = 7);   // #2 okay, adds a default

void h(){
    f(3);               // #1 and #2 are in scope, makes a call to f(3,7)
//    void f(int = 1, int);   // error, inner scope declaration do not acquire defaults
}

void m(){               // new scope begins
    void f(int, int);   // inner scope declaration; hos no defaults.
//    f(4);               // error, not enough argument to call f(int, int)
    void f (int , int =6); // now has a default parameter
    f(4);               // okay, call f( 4, 6)
//    voif f(int,int=6);  // error, cannot replaced a default in the same scope
}

void f(int=1, int);     // #3 adds a default to #2

void n(){               // new scope begins
    f();                // #1, #2 and #3 are in scope, calls f(1,7)
}

int main(){


}

