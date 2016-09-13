/**

/// Expression
/// user-defined conversion.
/// in general

Conversion function to its own ( possibly cv-qualified ) class ( or to a reference to it )
to the base of its own class ( or to a reference to it), and to the type void can be defined,
but can not be executed as part of the conversion sequence, except, in some case, through
'virtual' dispatch

**/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
/// user defined
//#include "temp.h"

struct B {};
struct X : B {
    operator B& () { return *this;}
};

int main(){
    X x;
    B& b1 = x;                  // does not call X::operator B&()
    B& b2 = static_cast<B&>(x)  // does not call X::operator B&
    B& b3 = x.operator B&()     // calls X::operator&
}













