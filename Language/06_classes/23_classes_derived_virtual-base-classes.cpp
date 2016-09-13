/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    * derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    derived classes
    Any type class may be declared as derived form one or or more
    base classes which, in turn, may be derived from their own base
    classes, formating an inheritance hierarchy.

    Syntax:
    attribute (optional) : access-specifier(optional) virtual-specifier(optional) class-or-decltype

    Note:
    If access-specifier is omitted ( leave out ), it defaults to 'public' for classes
    declared with class-key 'struct' and to 'private' for classes declared class-key 'class'

*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// virtual base classes

struct B {int n;};
class X : public virtual B {};
class Y : virtual public B {};
class Z : public B {};

// every object if type C  has one X, one Y, one X and two B's:
struct C : X, Y, Z {
    void f(){
        X::n = 1;   // modifies the virtual B sub-object's member
        Y::n = 2;   // modifies the same virtual B sub-object's member
        Z::n = 3;   // modifies the non-virtual B sub-object's member


        std::cout<<X::n<<' '<<Y::n<<' '<<Z::n<<std::endl;
    }
};

int main(){
    C c;
    c.f(); // output 2 2 3
}
