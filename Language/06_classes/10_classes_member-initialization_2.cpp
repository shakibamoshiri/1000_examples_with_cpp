/*
Classes
    - class declaration
    - union declaration
    * non-static member data
    - non-static member function
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
    non-static member data

*/

#include <iostream>
#include <string>
#include <vector>

/// Member initialization

//  if a member has a default member initializer and also appears in the
// member initialization list in a constructor, the default member initializer
// is ignored
int x = 0;
struct M {
    int n = ++x;
    M() {}  // uses default member initializer
    M(int t) : n (t) {} // uses member initializer list
};

int main(){
    std::cout<<"x : "<<x<<std::endl; // x : 0

    M m1;
    std::cout<<"x : "<<x<<std::endl; // x : 1, because of x++ inside the struct M

    M m2(10);
    std::cout<<"x : "<<x<<std::endl; // x : 1, still, because the default member initializer is ignored
                                    // it means this line: int n = ++x does not run
                                    // and the value of n initializes through M(int t) : n(t)
}
