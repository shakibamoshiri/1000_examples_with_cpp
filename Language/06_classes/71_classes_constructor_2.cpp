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

/// kinds of constructor
// Constructors have no name and cannot be called directly. They are invoked when
// initialization takes place, and they are selected according to the rules of
// initialization. The constructor without 'explicit' specifier are "converting
// constructor". The constructor with a 'constexpr' specifier nake their type a
// LiteralType. Constructor that may be called without any argument are "default constructors."
// Constructor that take another object of the same type as the argument are "copy constructor"
// and "more constructor"
/// so we have
// converting constructor   : without 'explicit'
// literal-type constructor : with 'constexpr'
// default constructor      : have no argument
// copy constructor         : takes the same object of its class
// move constructor         : takes the same object of its class

class X {
private:
    int a,b,i,j;
public:
    const int& r;
    X(int i):
        r(a),       // initializes X::r to refer to X::a
        b{i},       // initializes X::b to the value of the parameter i
        i(i),       // initializes X::i to the value of the parameter i
        j(this->i) // initializes X::j to the value of X::i
    {}

};p


int main(){
}



