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

struct Derived; // froward declaration
struct Base {
protected:
    int n;
private:
    void g(Base&, Derived&);


    friend void fm(Base*, Derived*);
};

struct Derived: Base {
    int m;      // public data member
    void f(Base& b, Derived& d){
        ++d.n;      // okay, i here is public
        ++n;        // okay, itself i
//        ++b.n;      // error, n belongs Base class and there, n is protected and not public
    }
};

void Base::g(Base& b, Derived& d){
    ++n;        // okay, modifies its n, n is protected, and g is a member function
                // so g accesses to modify n
    ++b.n;      // okay, object of b, can modify in a member function of its class
    ++d.n;      // okay, because n inside Derived class is a public member and not
                // a protected or private member so we can modify it
}
// friend function
void fm(Base* b, Derived* d){
    b->n;   // okay fm is a friend function inside base class
    d->n;   // okay fm is a friend function inside base class

    d->m;   // already it is public, no need to use friend function
}




int main(){

}






