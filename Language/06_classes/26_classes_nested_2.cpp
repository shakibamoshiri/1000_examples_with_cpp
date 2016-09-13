/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    * nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    nested classes ( nest verb: 2 oxford: to put types of information together, or inside each other )
    A declaration of class / struct or union may appear in within another class.
    Such declaration declares nested class.
    Note:
    Declaration of a nested class can use only types of names, static member,
    and enumeration from the enclosing class.
    Note:
    Declaration in a nested class can use any member of the enclosing class.
*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// nested class
// A friend function has no special access to the member of the enclosing class.
//
// Out-of-class definition of the members of nested class appears in the namespace
// of the enclosing class
struct enclose {
    struct inner {
        static int n;   // declaration
        void f(int);  // declaration
    };
};

// definition
int enclose::inner::n = 1;       // okay
void enclose::inner::f(int i){} // okay

int main(){
    std::cout<<enclose::inner::n<<std::endl;    // 1

    // object of inner class
    enclose::inner innerObject;
    std::cout<<innerObject.n<<std::endl;
    innerObject.f(-1);
}
