/*
Classes
    - class declaration
    - union declaration
    * non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    non-static member data

*/

#include <iostream>
#include <string>
#include <vector>

/// Usage
// the name of a non-static data member or a non-static member function
// can only appear in the following three situation:
// 1. As a part of class member access expression, in which the class either has this
// member or is derived form a class that has 'this' member, including the implicit
// 'this->' member access expressions that appear when a non-static member name is
// used in any of the context where 'this' is allowed ( inside member function,
// bodies, in member initializer lists, in the in-class default member initializers )
// Note: static member function has no 'this' pointer

struct A {
    int m;
    int n;
    int x = m;  // okay, implicit this allowed in default initializers (c++11)
    A (int t) : m(t), n(m) { // okay, implicit 'this' allowed in member initializers lists
        this->f();           // explicit member access expression
        f();                // implicit 'this' allowed in member function
    }
    void f();
};

// 2. to form a pointer to member
struct B {
    int m;
    void f();
};
int B::* p = &B::m;         // okay, use of m to make a pointer to member
void (B::* fp)() = &B::f;   // okay, use of f to amke a pointer to member

// 3. in unevaluated operands
struct C {
    int m;
    static const std::size_t sz = sizeof m;     // okay, m in unevaluated operand, we can do also sizeof int instead of sizeof m
};
std::size_t i = sizeof(C::m + 43);              // okay, even though there is no "this" object for m

int main(){
}
