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
    - abstract class                * copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    copy assignment operator
    A copy assignment operator of class T is a non-template non-static
    member function with the name operator= that takes exactly one
    parameter of type T, T&, const T&, volatile T&, or const volatile T&,
    for a type CopyAssignment, it must have a public copy assignment operator.

    Syntax:
    class-name& class-name :: operator=( class-name )
    class-name& class-name :: operator=( class-name& )
    class-name& class-name :: operator=( class-name ) = delete;
    class-name& class-name :: operator=( class-name ) = default;
*/

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

// #include <cstdlib>

/// copy and swap
// Copy assignment operator can be expressed in terms of copy constructor
// , destructor, and the swap() member function. if one is provided:
//  T& T::operator=(T arg){     // copy / move / constructor is called to construct arg
//  swap( arg );                // resource exchanges between *this and arg
//  return *this;
//  }                           // destructor is called to release the resources formerly held by *this

struct A {
    int n;
    std::string s1;
    // user-defined copy assignment, copy-and-swap form
    A& operator=(A other){
        std::cout<<"copy assignment of A"<<std::endl;
        std::swap(n, other.n);
        std::swap(s1, other.s1);
        return *this;
    }
};
struct B: A {
    std::string s2;
    // implicit-defined copy assignment
};
struct C {
    std::unique_ptr<int[]> data;
    std::size_t size;
    // non-copy and swap assignment
    C& operator=(const C& other){
        // checks for self-assignment
        if(this == &other )
            return *this;
        // reuse storage when possible
        if(size != other.size ){
            data.reset(new int[size]);
            size = other.size;
        }
        std::copy(&other.data[0], &other.data[0]+size, &data[0]);

        return *this;
    }
};


int main(){
    // base class
    A a1, a2;
    std::cout<<"a1 = a2 calls: ";
    a1 = a2;

    // derived class
    B b1, b2;
    b2.s1 = "one";
    b2.s2 = "two";
    // b1 == nothing
    std::cout<< "b1 = b2 calls: ";
    b1 = b2;    // copy all value of b2 to b1
                // implicitly-defined copy assignment

    std::cout<< "b1.s1 = "<< b1.s1<< " b1.s2 = "<< b1.s2 <<std::endl;
}
