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


/// access specifier, private member class
class enclose {
private:
    class nested {
    public:
        void n(){
            std::cout<<"enclose::nested::n()"<<std::endl;
        }
    };
public:
    typedef nested NClass;
    static nested Nc () { return nested();}
};

int main() {

//    enclose::nested a;      // error, nested is a private member
    enclose::NClass b;      // okay, it is a public member;
    b.n();

    enclose::Nc().n();
}






