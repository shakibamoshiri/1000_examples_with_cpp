/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              - this pointer
    - nested class                  - constructor
    - derived class                 * default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Default constructor
    A default constructor is a constructor which can be called with no
    argument. Either defined with an empty parameter list, or with default
    argument provided for every parameter. A type with a public default
    constructor is DefaultConstructible

    Syntax:
    class-name();
    class-name::class-name();
    class-name() = delete;
    class-name() = default;
*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>


struct A {}; // by default has an A::A()
struct B {
    B( const char* ){} // now by default has no default constructor
    // so if this constructor does not match when an object is created
    // compiler gave ERROR
};
struct C {
    const char* name;
    C(const char* t): // okay , it is match, but by default still exists copy,move,assignment constructor
        name(t) {}
};

int main(){
    A b;
//    B b;    // error: conflicting declaration ‘B b’
    C c("okay");
    C c2("aslo okay");
    c = c2;
    std::cout<<c.name<<std::endl;  // output: "also okay"

    C c3(c);    // copy constructor, by default exists
    std::cout<<c3.name<<std::endl;

    C c4("move is called");
//    c4(std::move(c3));      // error it is not the move constructor


    C c5( C("The move constructor by default is exists.") );   // okay, it is a move constructor
    std::cout<<c5.name<<std::endl;
}



