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
#include <utility>
// #include <cstdlib>

/// Example
struct A {
    std::string s;
    A(): s("empty"){}
    A(const A& obj): s(obj.s){
            std::cout<<"move failed"<<std::endl;
    }
    A(A&& obj): s(std::move(obj.s)){}
    A& operator=(const A& other){
          this->s = other.s;
          std::cout<<"copy assignment...\n";
          return *this;
    }
    A& operator=(A&& other){
        this->s = std::move(other.s);
        std::cout<<"move assignment...\n";
        return *this;
    }
};
// like copy constructor
A f(A a){return a;}

struct B: A {
    std::string s2;
    int n;
    // implicit move assignment operator B& B::operator=(B&&)
    // calls A's move assignment operator
    // calls s2's move assignment operator
    // and makes a bitwise copy of n
};
struct C: B {
    ~C(){}  // destructor prevents implicit move assignment
};
struct D: B {
    D(){}
    ~D(){} // destructor prevents implicit move assignment
    D& operator=(D&&) = default;    // force a move assignment anyway
};


int main(){

    A a1, a2;
    std::cout<<"Try to move-assign A from r-value temporary\n";
    a1 = f(A());    // move assignment from r-value temporary
    std::cout<<"Trying to move-assign A from x-value\n";
    a1 = std::move(a2); // move assignment from x-value

    std::cout<<"Trying to move assign B\n";
    B b1, b2;
    std::cout<<"Before move, b1.s = \""<<b1.s<<"\"\n";
    b2 = std::move(b1); // calls implicit move assignment
    std::cout<<"Before move, b1.s = \""<<b1.s<<"\"\n";

    std::cout<<"Trying to move-assign C\n";
    C c1, c2;
    c1 = std::move(c2); // calls the copy assignment operator
                        // because C has an destructor that prevents implicit move assignment
    std::cout<<"Trying to move-assign D\n";
    D d1, d2;
    d2 = std::move(d1);


}
