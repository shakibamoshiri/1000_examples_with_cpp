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
// Non-static data member may be initialized in one of two ways:
// 1. in the member initializer list of the constructor
struct S {
    int n;
    std::string s;
    S() : n(7) {}     // direct-initializes n, default-initializes s ( "" )
};

// 2. through a default member initializer, which is simply a brace or equal
// initializer include in the member declaration, which is used if the member
// is omitted in the member initializer list
struct N {
    int n = 7;
    std::string s{'a', 'b', 'c'};
    N(){}   // copy-initializes n, list-initializes s
};



int main(){
}
