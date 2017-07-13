/**
/// constant / volatile type qualifier
///
Appear in any type specifier, including decl-specifier-seq of declaration grammar
to specify constants or volatile of the object being declared or of the type being named.
    - const     defines that the type is constant
    - volatile  defines that the type is volatile
    - mutable   applies to non-static class member of non-reference non-const type
    and specifiers that the member does not affect that externally visible state of
    the class.

When an object is first created, the cv-qualifiers used ( which could be part of
decl-specifier-seq or part of a declarator in declaration, or part of type-id in
a new-expression ) determine the constants or volatility of the object, as following:
    - const object      an object whose type is const-qualified, or non-mutable subobject
                        Such object cannot be modified: attempted to do so directly is a
                        compile time error, and attempted to do so indirectly ( e.g. by
                        modifying the const object through a reference or pointer to non
                        -const type result in undefined behavior.
    - volatile object   an object whose type is volatile-qualified or a sub-object of a
                        volatile object or a mutable sub-object of a const-volatile object.
                        Every access ( read and write operation, member, function, call, etc )
                        on the volatile object is treated as a visible side-effect for the
                        purposes of optimization ( that is within a single thread of execution
                        , volatile accesses cannot be reordered or optimized out. This make
                        volatile object suitable for communication with a single handler,
                        but not with another thread or execution. Any attempt to refer to a
                        volatile object through a non-volatile gl-value ( through reference
                        or pointer or non-volatile type ) results is undefined behavior.
    -const volatile object      an object whose type is const-volatile-qualified, a non-mutable
                        sub-object of a const volatile object, a const sub-object of a volatile
                        object, or a non-mutable volatile sub-object of a const object. Behaves as
                        both a const object and a as volatile object.

There is partial ordering of cv-qualified by the order of increasing restrictions.
The type can be said more or less cv-qualified then:
    unqualified < const
    unqualified < volatile
    unqualified < const volatile
    const < const volatile
    volatile < const volatile

**/
#include <iostream>
#include <string>

int main(){
    int n1  = 0;            // non-const object
    const int n2 = 0;       // const object
    int const n3 = 0;       // const object (same as n2)
    volatile int n4 = 0;    // volatile object

    const struct {
        int n1;
        mutable int n2;
    }x = {0 , 0};   // const object with mutable member

    n1 = 1;         // okay, modifiable object
//    n2 = 2;         // error, non-modifiable object
    n4 = 4;         // okay treated as a side-effect
//    x.n1 = 1;       // error, member of a const object is const
    x.n2 = 3;       // okay, mutable member of a const object is not const

    const int& r1 = n1;         // reference to const bound to non-count object
//    r1 = 3;                     // error, attempt to modify through reference to object
    const_cast<int&>(r1) = 22;  // okay, modifies non-const object n1

    const int& r2 = n2;         // reference to const bound to const object
//    r2 = 33;                    // error, attempt to modify through reference to const
    const_cast<int&>(r2) = 33;  // undefined behavior, attempts to modify const object n2
    std::cout<<n2; // output 0
}











