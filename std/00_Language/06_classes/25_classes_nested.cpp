/*
Classes
    - class declaration
    - union declaration
    - non-static member data
    - non-static member function
    - static specifier              - bit field
    * nested class                  - constructor
    - derived class                 - default constructor
    - using declaration             - destructor
    - virtual function specifier    - copy constructor
    - abstract class                - copy assignment operator
    - access specifier              - move constructor
    - friend declaration            - move assignment operator
    - override specifier            - converting operator
    - final specifier               - explicit specifier
***************************************************************
    nested classes ( nest verb: 2 oxford: to put types of information together, or inside each other )
    A declaration of class / struct or union may appear in within another class.
    Such declaration declares nested class.
    Note:
    Declaration of a nested class can use only types of names, static member,
    and enumeration from the enclosing class.
    Note:
    Declaration in a nested class can use any member of the enclosing class.
*/

#include <iostream>
#include <string>
#include <utility>
#include <exception>

/// nested class
int x,y;    // global values
class enclose {
    int x;          // private data member
    static int s;   // static data member
public:
    struct inner {
        void f(int i){
//            x = i;      // error, can not write to non-static enclose::x without instance
                        // that you can with an object, enclose e; e.x = 0;
            int a = sizeof x;   // error until c++11, and okay after that
                                // like above reason, x is a non-static member
            int b = sizeof s;   // okay
            s = i;              // okay, can assign to the static enclose::s
            ::x = i;            // okay, can assign to global x
              y = i;            // okay, can assign to global x
        }
        void g(enclose* p, int i){
            p->x = i;           // okay, assign to enclose::x with an instance of the class enclose ( *p )
        }
    };
    void f(){
        std::cout<<"x: "<<x<<" static s: "<<s<<std::endl;
    }
};

// definition static s of class enclose
int enclose::s = 10;

int main(){
    enclose one;

    enclose::inner one_inner;
    one_inner.f(11);    // so, now, static s = 11
                        // and global x is 11
                        // and global y is 11

    one.f();            // x: 0, (or unknown value) and s: 11

    one_inner.g(&one, 11);  // now p->x = 11;

    one.f();                // x: 11 and static s: 11
}
