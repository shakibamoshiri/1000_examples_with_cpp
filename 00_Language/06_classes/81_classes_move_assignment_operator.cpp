/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              - this pointer
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            * move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    move assignment operator
    A move assignment operator of class T is a non-template non-static
    member function with the name operator= that takes exactly one parameter
    of type T&&, with const or volatile or const volatile

    syntax:
    class-name& class-name:: operator= ( class-name&& )
    class-name& class-name:: operator= ( class-name&& ) = default;
    class-name& class-name:: operator= ( class-name&& ) = delete;
*/

#include <iostream>
#include <string>
#include <iomanip>
// #include <cstdlib>

/// move-assignment and virtual base class
// As with copy assignment, it is unspecified whether virtual base class
// sob-objects that are accessible through move than one path in the
// inheritance lattice, are assigned more than once by the implicitly
// defined move assignment operator:

struct V {
    V& operator=(V&& other){
        std::cout<<"V::operator= was called\n";
        // this may be called one or twice
        // if called twice, 'other' is the just-move-form V sub-object
    }
};
struct A: virtual V {};     // operator= calls V::operator=
struct B: virtual V {};     // operator= calls V::operator=
struct C: A, B {};          // operator=, calls B::operator, then A::operator
                            // but they may only called V::operator= once

int main(){
    C c1, c2;
    c2 = std::move(c1);
}
