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
// Nested class can be forward-declared and later defined,
// either within the same enclosing class body, or outside of it.

class enclose {
    class nested_1;     // forward-declared
    class nested_2;     // forward-declared
    class nested_3 {};  // definition of nested class inside the enclose class
};

class enclose::nested_1 {}; // definition of nested class, outside
class enclose::nested_2 {}; // definition of nested class, outside


int main(){

}
