/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    * non-static member function
    - static specifier              - bit field
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
    non-static member function
    A non static member function is a function that is declared in member
    specification of a class without a 'static' or 'friend' specifier

*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// virtual and pure virtual function
// A non-static member function may be declared virtual or pure virtual.

/// Special member function
// constructor and destructor are non-static member function that are
// defined by the compiler even if not defined by the user. They are:
//
//  - default constructor
//  - copy constructor
//  - move constructor since c++11
//  - copy assignment operator
//  - move assignment operator since c++11
//  - destructor
//
// Special member function are the only function that can be defaulted,
// that is, defined using '= default' instead of the function body.

struct S {
    int data;

    // simple converting constructor ( declaration )
    S(int val);

    // simple explicit constructor ( declaration )
    explicit S(std::string str);

    // const member function ( declaration )
    virtual int getData() const { return data;}
};
// definition of the constructor
S::S(int val): data(val){
    std::cout<<"constructor 1 was called, data = "<<data<<std::endl;
}

// this constructor has a catch clause
S::S(std::string str) try: data(std::stoi(str)){
    std::cout<<"constructor 2 was called, data = "<<data<<std::endl;
} catch ( const std::exception&) {
    std::cout<<"constructor 2 filed, string was: "<<str<<std::endl;

    throw;  // constructor's catch clause should always re-throw
}


struct D : S {
    int data2;

    // constructor with a default argument
    // and in-line initialization
    // first call base class S
    D(int d1, int d2=0): S(d1), data2(d2){}

    // virtual member function override
    int getData() const override {
        return data + data2;
    }

    // l-value only assignment operator
    D& operator=(D other) & {
        std::swap(other.data, data);
        std::swap(other.data2, data2);
        return *this;
    }
};

int main(){
    D d1 = 1; // data = 1, data2 = 0 (  default initializer d2=0 )
    S s1("2");
    try {
        S s2("no number");
    } catch (const std::exception&){}

    std::cout<<s1.getData()<<std::endl;

    D d2(3,4);
    d2 = d1;    // okay, assignment to l-value
//    D(5) = d1;  // error, no suitable overload of operator=
    std::cout<<d2.getData()<<std::endl;
}
