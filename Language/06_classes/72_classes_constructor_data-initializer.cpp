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
/// two note about initialization

// If a non-static data member has an in-class-brace-or-equal initializer
// and also appears in a member initializer list,(manes constructor) then
// initializer list is executed and brace-or-equal initializer is ignored.

struct D {
    int n = 33;
    D(): n(99) {} // it will set to 99 and not to 33
};

// Reference member cannot be bound to temporaries in a member initialize list
struct B {
    B(): v(33) {}
    const int& v;
    const int& w=11;
};

struct C {
    const int& v=21;
    const int&& w=22;
    const int e=23;
};

int main(){
    std::cout<<D().n<<std::endl;    // output: 33

    std::cout<<B().v<<std::endl;    // output 0
    std::cout<<B().w<<std::endl;    // output 0
    B b1;
    std::cout<<b1.v<<std::endl;     // output 0
    std::cout<<b1.w<<std::endl;     // output 0

    std::cout<<C().v<<std::endl;    // output 0
    std::cout<<C().w<<std::endl;    // output 0
    std::cout<<C().e<<std::endl;    // output 23
}



