/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function    - bit filed
    - static specifier              * this pointer
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
    this pointer
    The keyword 'this' is a pr-value expression whose value is the address
    of the object, on which the member function is being called. It can
    appear in the following contexts:
    1   within the body of any non-static member function
    2   within the declaration of a non-static member function
    3   within default member initializer since c++11

    for every non-static member function non-cv-qualified it is *this
    but for every non-static member-function cv-qualified it is cv *this

    Since constructor and destructor cannot be cv-qualified, the type of
    'this' in them is always X*, even when constructing or destructing
    a constant object.
*/

#include <iostream>
#include <string>
#include <sstream>
// #include <cstdlib>

/// this
class C {
    int x;
    void f(){       // it has C* this
        x = 54;
        this->x = 77;
    }
    void f() const { // it has cosnt C* this
//        this->x = 33;   // error
    }
    void f(int t){    // it has C* this
        this->x = t;
    }
    int y;
    C(int t): x(t), y(this->x) {}
    C& operator=(const C& t){
        this->x = t.x;
        return *this;
    }
};

class External {
//    int a[sizeof(*this)];       // error, not inside a member function
    unsigned int sz = sizeof (*this);   // okay, in default member initializer
    double dd;
    void f(){
        int b[sizeof(*this)];   // okay

    }
    public:
    const int d() {
        return this->sz;
    }
        struct Inernal {
//            int c[sizeof(*this)];   // error, not inside a member function
        };
};

int main(){
    std::cout<<External().d(); // output is 12 ( 4 int + 8 double )
}







