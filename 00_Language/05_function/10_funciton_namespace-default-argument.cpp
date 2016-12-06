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

// default in namesapce
// the using-declaration carries over the set of known default argument
// and if more arguments are added later to the function's namespace,
// those defaults are also visible anywhere the using-declaration is visible

namespace N {
    void f (int, int=1);
}

using N::f;
void g(){
    f(7);   // call f(7,1);
//    f();    // error
}
namespace N {
    void f(int=2, int); // adds to f (int, int=1)
}
void h(){
    f();    // class f(2,1)
}

int main(){


}

