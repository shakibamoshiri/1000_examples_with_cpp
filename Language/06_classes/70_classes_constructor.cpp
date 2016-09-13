/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              - this pointer
    - nested class                  * constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    constructor and member initializer lists
    Constructor is a special non-static member-function of a class
    that is used to initialize objects of its class type.

    The only specifiers allowed in the declaration-specifier-sequence
    of a constructor  are 'friend', 'inline', 'explicit', and 'constexpr'.
    In particular, no return type is allowed, and no cv-qualified are
    allowed either.

    The body of a function definition of any constructor, before the opening
    brace of the compound statement( means {} ) may include the 'member initializer list',
    whose syntax is the color character (:,) and following by comma-separated list of
    or more member-initializers, echo of which has the following syntax:
    class-or-identifier (expression list)
    class-or-identifier brace-init-list     c++11
    parameter-pack list ...                 c++11

*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>

struct Con {
    int n;
    Con(int);       // constructor declaration
    Con(): n(7){}   // constructor definition
                    // ": n(7)"     is the initializer list
                    // ": n(7) {}"  is the function body
};

Con::Con(int t): n{t} {}    // constructor definition. ": n{t}" is the initializer list

int main(){
    Con n1;     // calls Con::con()
    Con n2(39); // calls Con::Con(int)
}



