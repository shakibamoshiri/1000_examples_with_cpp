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



struct C {
    const char* name;
    C(const char* t): // okay , it is match, but by default still exists copy,move,assignment constructor
        name(t) {}
    void f(){
        std::cout<<this->name<<std::endl;
    }
};

int main(){
    // print out in regular way
    C c1("first object");
    c1.f();

    // print out also by move constructor. ( NOTE: I am not not sure that would be move-constructor, maybe its name would be temporary object, I do not know)
    C("move").f(); // maybe temporary object with  move-constructor


    C c2("move assignment = ");
    c1 = std::move(c2);

    c1.f(); // default move-assignment gave no error, but does not work, c1 still exists
    c2.f(); // c2 becomes: "move assignment = "


}



