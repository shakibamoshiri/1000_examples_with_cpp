/**

/// Expression
/// Implicit Conversions
/// dynamic_cast
dynamic_cast< new_type > ( expression )

Safely coverts pointers and references to classes up, down, and
along the inheritance hierarchy.

new_type    pointer to complete class type, reference to complete
            class type, or pointer to ( optionally cv-qualified ) void
expression  L-value of a complete class type if new_type is a reference
            prvalue of a pointer to complete class type if new_type is a pointer
If the cast is successful, dynamic_cast returns a value of new_type. If the cast
fails and new_type is a pointer type, it returns a null pointer of that type. If
the cast fails and new_type is a reference type, it throw an exception that matchs
a handler of type std::bad_cast.


**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

struct V {
    virtual void f() {} // must be polymorphic to use runtime-checked dynamic_cast
};
struct A : virtual V {};
struct B : virtual V {
    B(V* v, A* a){
        // casts during construction ( see the call in the constructor of D below )
        dynamic_cast<B*>(v); // well-defined: v of type V* , v base of B, result in B*
        dynamic_cast<B*>(a); // undefined behavior: a has type A*, A not a base of B
    }
};
struct D : A, B {
    D() : B((A*)this, this) {}
};
struct Base {
    virtual ~Base() {}
};
struct Derived : Base {
    virtual void name() {}
};

int main(){
    D d; // the most derived object
    A& a = d; // up-cast, dynamic_cast may be used, but unnecessary
    D& new_d = dynamic_cast<D&>(a); //down-cast

    B& new_b = dynamic_cast<B&>(a); // side-cast

    Base* b1 = new Base;
    if ( Derived* d = dynamic_cast<Derived*>(b1) ){
        std::cout<<"down-cast form b1 to d successful\n";
        d->name(); // safe to call
    }

    Base* b2 = new Derived;
    if ( Derived* d = dynamic_cast<Derived*>(b2) ){
        std::cout<<"Down-cast from b2 to d successful\n";
        d->name(); // safe to call
    }

    delete b1;
    delete b2;
}













