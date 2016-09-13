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
    - access specifier              * move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    move constructor
    A move constructor of class T is a non-template constructor whose
    first parameter is T&&, const T&&, volatile T&& or const volatile T&&,
    and either are no other parameter, or the rest of the parameter all
    have default values.

    syntax:
    class-name ( class-name && )
    class-name ( class-name && ) = delete;
    class-name ( class-name && ) = default;

    Move constructor is called whenever an object is initialized from
    x-value of the same type, which include:
    ...
*/

#include <iostream>
#include <string>
#include <iomanip>
// #include <cstdlib>

struct A {
    std::string s;
    A():
        s("test"){}
    A(const A& obj):
        s(obj.s){
            std::cout<<"move failed!"<<std::endl;
    }
    A(A&& obj) noexcept:
        s(std::move(obj.s)){}
};

A f(A a){ return a;}

struct B: A {
    std::string s2;
    int n;
    // implicit move constructor B::( B&& )
    // calls A's move constructor
    // calls s2's move constructor
    // and makes a bitwise copy of n
};
struct C: B {
    /// C(){}

    ~C(){}  // destructor prevents implicit move constructor

    /// C(C&&) = default;
};
struct D: B {
    D(){}
    ~D(){}  // destructor would prevent implicit move constructor
    D(D&&) = default;   // force a move constructor anyway
};



int main(){

    std::cout<< "Trying to move A\n";
    A a1 = f(A());          // move constructor from r-value temporary
    A a2 = std::move(a1);   // move-constructor form x-value

    std::cout<<"Trying to move B\n";
    B b1;
    std::cout<<"Before move, b1.s = "<<std::quoted(b1.s)<<std::endl;
    B b2 = std::move(b1);   // calls implicit move-constructor
    std::cout<<"After move, b1.s = "<<std::quoted(b1.s)<<std::endl;

    std::cout<<"Trying to move C\n";
    C c1;
    C c2 = std::move(c1);   // calls the copy constructor

    std::cout<<"Trying to move D\n";
    D d1;
    D d2 = std::move(d1);

}
