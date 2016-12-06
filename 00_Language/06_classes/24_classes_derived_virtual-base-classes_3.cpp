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

/// derived classes
// All virtual base sob-objects are initialized before any non-virtual
// base sub-object, so only the most derived class calls the constructor
// of the virtual bases in its member initializer list.

struct B {
    int n;
    B(int i): n(i){}
};

struct X : virtual B {
    X(): B(1){}
};
struct Y : virtual B {
    Y(): B(2) {}
};
struct Compound : X, Y {
    Compound(): B(3), X(), Y() {}
};
// the default constructor of Compound calls the default constructors of X and Y
// but those constructors do not call the constructor of B because B is a virtual
// base.

int main(){
    X x;
    std::cout<<x.n<<std::endl;

    Y y;
    std::cout<<y.n<<std::endl;

    Compound c;
    std::cout<<c.n<<std::endl;

}
