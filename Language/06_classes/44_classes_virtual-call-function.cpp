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
#include <cstdlib>


/// virtual, during construction and destruction

struct V {
    virtual void f(){
        std::cout<<"V::f"<<std::endl;
    };
    virtual void g(){
        std::cout<<"V::g"<<std::endl;
    };
};
struct A : virtual V {
    virtual void f(){   // A::f is the final overrider of V::f in A
        std::cout<<"A::f"<<std::endl;
    }
};
struct B : virtual V {
    virtual void g(){   // B::f is the final overrider of V:::g in B
        std::cout<<"B::g"<<std::endl;
    }
    B(V*, A*);          // constructor of B
};
// struct D, have no act in this case,
struct D : A, B {
    // so here are A constructor
    // and         B constructor
    // but not     V constructor
    virtual void f(){
        std::cout<<"D::f"<<std::endl;
    }
    virtual void g(){
        std::cout<<"D::g"<<std::endl;
    }

    // note: A is initialized before B
    D(): B( (A*)this, this) {}
};

// B constructor definition
B::B(V* v, A* a){
    f();        // virtual calls V::f ( although D has the final overrider, D does not exist )
    g();        // virtual calls B::g, which it the final overrider in B
    v->g();     // v's type V is base of B, virtual call calls B::g as before
    a->f();     // a'a type is A is not a base of B, it belongs to a different branch of the
}





int main() {
    V v;
    A a;
    B (&v, &a);
/*
    V::f
    B::g
    V::g
    A::f

    Process returned 0 (0x0)   execution time : 0.016 s
    Press ENTER to continue.
*/
}






