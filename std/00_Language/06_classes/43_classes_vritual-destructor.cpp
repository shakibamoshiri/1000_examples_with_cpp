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
    * virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    virtual function specifier
    Specific that a non-static member function is virtual and supports dynamic binding
*/

#include <iostream>
#include <string>
#include <cstdlib>


/// virtual destructor
// Even though destructor are not inherited, if a base class declares its destructor
// 'virtual', the derived destructor always overrides it. This makes it possible to
// delete dynamically allocated objects of polymorphic type through pointers on base

class Base {
public:
    virtual ~Base(){
        // releases base's resources
    }
};
class Derived :Base {
public:
    ~Derived(){
        // releases Derived's resources
    }
};

int main() {
    Base* p = new Derived;
    delete p;   // Makes a virtual function call to Base::~Base()
                // since it is virtual, it calls Derived::~Derived()
                // which can release resources of the derived class, and then
                // calls Base::~Base() following the usual order of destruction.
}






