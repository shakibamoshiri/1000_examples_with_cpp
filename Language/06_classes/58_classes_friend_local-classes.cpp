/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    * friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Fried Declaration
    The friend declaration appears in a class body and grants a function
    or another class access to private and protected members of the class
    where the friend declaration appears.
    (grant means: to agree to give someone what they ask for,
     especially formal or legal permission to do something )

     Syntax:
     friend function-declaration
     friend function-definition
     friend elaborated-class-name ; ( elaborated means: very complicated and detailed; carefully prepared and organized)
     friend simple-type-specifier ;
     friend typename-specifier ; since c++11
*/

#include <iostream>
#include <string>
// #include <cstdlib>


/// local class and friend
// when a local class declares an unqualified function or class
// as a friend, only function and  classes in the innermost ( innermost means: ( also less frequent in-most ) most private, personal and secret )
// non-class scope are looked up not the global function

class F {};
int f();

int main(){
    extern int g();
    class Local {           // local class is the main() function
//        friend int f();     // error, no such function declared in the main()
//        friend int ::f();     // error, also with :: or without it
        friend int g();     // okay, this is a declaration for g() in the main()
        friend class ::F;   // friends the global F
        friend class F;     // friends as local class F, friend class froward declaration, ( defines later )
    };
    class F{};              // local F
}







