/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    * static specifier              - bit field
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
    static specifier
    Inside a class, declares members not bound to specific instances ( instance means: a particular example or case of something )

    syntax:
    static data member      : declares a static data member
    static function member  : declares a static function member

*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// static data member
// Static data member are not associated with any object.
// They exist even if no objects of the class have been
// defined. If the static member is declared thread_local
// (since c++11) there is no one such object per thread.
// NOTE:
// Static data member can not be mutable.


/// static member function
// Static member function are not associated with any object.
// When called, they have no 'this' pointer.
// Static member function can not be 'virtual', 'const', or 'volatile'.
// NOTE:
// The address of a static member function may be stored in a regular
// pointer to function, but not in a pointer to member function

struct S {
    static int i;
    static int f() { return i;}
};

int S::i = 0;


int main(){
    S s1;
    s1.i = 1;
    std::cout<<s1.i<<std::endl; // output is 1

    // regular pointer is okay
    int* pi = &S::i;

    // okay
    std::cout<<*pi<<std::endl; // output is 1

    // this is wrong
//    int S::* pi = &S::i;

    // regular pointer to function, okay
    int (*pf)() = &S::f;

    // this is wrong, because, it is not a pointer member
    // std::cout<<s1.*pf<<std::endl;

    // okay return i form S::i
    std::cout<<pf()<<std::endl; // output is 1

    // this is wrong
//    int (S::* pf)() = &S::f;
}
