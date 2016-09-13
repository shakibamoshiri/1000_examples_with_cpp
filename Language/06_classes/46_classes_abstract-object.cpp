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
    * abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Abstract Class ( almost opposite: Concrete class)
    Defines an abstract type which can not be instantiated, but can be used as a base class

    pure-virtual function is a virtual-function that = to 0
    declaration virtual-function (optional) = 0;

    Note: pure-specifier ( 0 ) can not appear in a member definition
*/

#include <iostream>
#include <string>
#include <cstdlib>


/// abstract class
// Abstract classes are used to represent general concepts ( for example, Shape)
// which can be use as base classes for concrete classes (for example, Circle)
// more detail about 'concrete' word: A concrete object is one that you can see and feel

// abstract class
struct Abstract {
    virtual void f()=0; // pure-virtual
};
// still definition of Abstract::f is possible
void Abstract::f(){
    std::cout<<"Abstract::f"<<std::endl;
}


struct Concrete: Abstract {
    void f() override {
        std::cout<<"Concrete::f"<<std::endl;
    }   // non-pure virtual
    virtual void g() {}     // non-pure virtual
};

// without any declaration, C is a abstract class,
// unless overrides function in a non-pure virtual
struct C : Abstract {};


struct Abstract2 : Concrete {
    void g() override = 0;  // non-virtual overrider
};

int main() {
    // create object of abstract class is wrong
//    Abstract a;

    Concrete c; // okay

    Abstract& ar = c; // okay, to reference abstract base class

    ar.f();     // calls Concrete::f and not Abstract::f

    // error , C is a abstract class
    // C cc;
}






