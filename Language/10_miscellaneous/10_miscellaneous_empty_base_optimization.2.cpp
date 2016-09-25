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

#include <cassert>

struct Base {};     // empty class

struct Derived1 : Base { int i; };      // it equal to sizeof ( int )

struct Derived2 : Base {
    Base c;         // Base, occupies ( take up ) 1 byte, followed by padding for i
    int i;
};

struct Derived3 : Base {
    Derived2 d2;    // derived form Base, occupies sizeof ( int ) bytes
    int i;
};

int main () {
    // empty base optimization does not apply,
    // base occupies 1 byte, Base member occupies 1 byte
    // followed by 2 bytes of padding to satisfy int alignment requirements

    assert( sizeof(Base) == 1 );

    assert(sizeof(Derived1) == sizeof (int));

    assert(sizeof(Derived2) == 2*sizeof(int));

    // empty base optimization does not apply,
    // base takes up at least 1 byte plus the padding
    // to satisfy alignment requirement of the first member
    // (whose alignment is the same as int )
    assert(sizeof(Derived3) == 3*sizeof(int));
}
