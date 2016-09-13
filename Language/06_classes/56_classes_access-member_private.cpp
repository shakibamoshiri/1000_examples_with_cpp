/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    - nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    * access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    Access Specifier
    In a member specification of a class / struct or union, define
    the visibility of subsequence member.
*/

#include <iostream>
#include <string>
#include <cstdlib>


/// access specifier, protected

class T {
private:
    int a, b, c;
public:
    T(){a=b=c=0;}
    T* t= this;

};


int main(){
    T one;
    one.a;      // error it is a private data member
    one.t->a;   // error again, a is a private member
}






