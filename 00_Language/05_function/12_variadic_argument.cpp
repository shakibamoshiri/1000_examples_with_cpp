/*
Function:
    declaring function
    default argument
*   variadic argument
    lambda function
    operator overloading
    address of overloading function
***************************************
     variadic argument
**********************
Allows a function to accept any number of argument.
Indicated by the parameter of the form '...' which must appear
last in the parameter-list of a function declaration. Where
syntactically correct, , ... may be replaced by ...

*/

// the function declared as function
int printx(const char* fmt, ...);

// may be called with one or more arguments
printx("hello word");
printx("a=%d b=%d", a, b);

int printx(const char* fmt, ...);   // same as above ( comma is optonal )
int printx(... , const char* fmt);  // error, ... must be appear at the last
int printx(...);                    // error, but the argument cannot be accessed protably

#include <iostream>
#include <string>
#include <array>

int main(){


}

