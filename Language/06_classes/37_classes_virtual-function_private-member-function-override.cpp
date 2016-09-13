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
    * virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    virtual function specifier
    Specific that a non-static member function is virtual and supports dynamic binding
*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// virtual function, private function member
// Private function member can be override as virtual function

class A {
private:
    virtual void pri_f () { std::cout<<"A::f() private virtual function\n";}
public:
    void pub_f() { pri_f(); }
};

struct B : A {
    virtual void pri_f() { std::cout<<"B::f() public virtual function\n";}
    // here are existence:
    // void pub_f() { pri_f(); }
};

int main(){
    B b;
    A* p = &b;
    p->pub_f(); // B::f() public virtual function
                // p call public function f, and f
                // calls pri_f inside B not inside A


}
