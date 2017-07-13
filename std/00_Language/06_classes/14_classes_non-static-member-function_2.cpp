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
#include <vector>

/// const, volatile, and ref-qualified member function
// A non-static member function can be declared with a
//    - const
//    - volatile
//    - const volatile
//    - &
//    - &&
// A non-static member function may still be called if const_cast is
// applied or through an access path that does not invoke this

struct Array {
    std::vector<int> data;
    Array(int t): data(t) {}
    // const member function
    int operator[] (int index) const {
        // here this has the type const Array*
        return data[index];
        // transformed to (*this).data[index];
        // also this-data[index]

        // here, if we want to change the value
        // we need to use const_cast
    }
    // non-const member function
    int& operator[] (int index){
        // here 'this' pointer has type Array*
        return data[index];
        // transformed to (*this).data[index]
        // also this-data[index]
    }
};

int main(){
    Array a1(10);
    a1[1] = 10;  // okay, the type of a[1] is int&

    const Array ca1(10);
//    ac1[1] = 10;    // error, the type of ca1[1] is int

}
