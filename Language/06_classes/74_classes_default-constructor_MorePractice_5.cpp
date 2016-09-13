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



struct B {
    int n;
    B(int t):
        n(t) {} // okay
    friend std::ostream& operator<<(std::ostream& out, const B& obj){
        return out << obj.n ;
    }
};
struct D: B {
    int m;
    D(int t1, int t2):
        B(t1),
        m(t2) {}
    friend std::ostream& operator<<(std::ostream& out, const D& obj){
        return out << obj.n <<' '<< obj.m;
    }
    friend std::istream& operator>>(std::istream& in, D& obj){
        return in >> obj.n >> obj.m;
    }
};


int main(){
    B b(11);
    std::cout<<b<<std::endl;

    D d(12,13);
    std::cout<<d<<std::endl;

    std::cout<<B(1)<<std::endl;

    std::cout<<D(2,3)<<std::endl;

    std::istringstream("4 5") >> d;
    std::cout<<d<<std::endl;
}



