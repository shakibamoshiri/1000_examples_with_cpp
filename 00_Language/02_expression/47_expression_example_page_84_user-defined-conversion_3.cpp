/**

/// Expression
/// user-defined conversion.
/// in general

operator conversion-type is
explicit operator conversion-type-id

Enable implicit conversion or explicit conversion from a class type to another type.
first: Declares a user-defined conversion function that participate in all implicit
       and explicit conversion.
second Declares a user-defined conversion function that participates in direct-initialization
       and explicit conversion only.

**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

struct D;
struct B {
    virtual operator D() = 0;
};
struct D : B {
    operator D() override { return D();}
};

int main(){
    D obj;
    D obj2 = obj; // does not call D::operator D()

    B& br = obj;
    D obj3 = br; // calls D::operator D() through virtual dispatch
}













