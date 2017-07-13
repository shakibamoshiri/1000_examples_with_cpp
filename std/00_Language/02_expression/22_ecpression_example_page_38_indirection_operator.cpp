///
/// Expression
///


/**
Built-in indirection operator *

For every type T that is either object type ( possible cv-qualified ) or
function type ( not const-or ref-qualified ), the following function ___
signature participates in overload resolution:  T& operator* (T*);

The operand of the built-in indirection operator is a pointer to object or
function, and the result is the l-value that the pointer is pointing to. _
Note that a pointer to incomplete type can be dereferenced, e.g. when __
initialing a reference.
**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"

int func() { return 30; }

int main(){
    int n = 1;
    int* pn = &n;

    int& rn = *pn; /// l-value can be bound to a reference
    int m = *pn;   /// indirection + l-value-to-r-value conversion

    int (*pfunc)() = &func;
    int (&rfunc)() = *pfunc;
    std::cout<<pfunc()<<std::endl;
    std::cout<<rfunc()<<std::endl;
}

