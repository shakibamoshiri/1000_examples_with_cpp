/*
Miscellaneous:
    01 asm declaration
    02 extending the namespace std
    03 undefined behavior
    04 RAII ( Resource Acquisition Is Initialization )
    05 The rule of three / five / zero
    06 The as-if rule
    07 copy elision

    08 Empty base optimization
*/
//
//
/// 08 empty base optimization
// Allows to the size of an empty base subobject to be zero.
//
// Explanation
// The size of any object of member subobject is required to be at least
// 1 even if the type is an empty class type ( that is a class or struct
// that has no non-static data member ) , in order to be able to guarantee
// that the addresses of distinct objects of the some type are always distinct.
// However, base class subobjcet are not so constrained, and can be completely
// optimized out from the object layout:

#include <iostream>
struct Base {};     // empty base

struct Derived1 : Base { int i; };

int main(){
    // the size of any object of empty class type is at least 1
    if ( (sizeof(Base) == 1 ))
        std::cout<<"oKay it     == 1\n";

    // empty base optimization applies
    if ( sizeof(Derived1) == sizeof(int) )
            std::cout<<"Okay it     == int\n";
}
