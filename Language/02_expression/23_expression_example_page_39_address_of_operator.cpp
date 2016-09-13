///
/// Expression
///


/**
Built-in address of operator

**/
#include <iostream>
#include <string>
#include <cassert>
/// user defined
//#include "temp.h"
void f(int){}
void f(double){}
struct A {int i;};
struct B {void f();};


int main(){
    int n = 1;
    int* pn = &n; /// pointer

    int A::* pAmo = &A::i;          /// pointer to member object
    void (B::* pBmf)() = &B::f;     /// pointer to member function

    void (*pfi)(int) = f;            /// overload resolution due to initialization context
    void (*pfd)(double) = f;         /// overload resolution due to initialization context

    /// error: unable to deduce ‘auto’ from ‘f’
    /// auto apfi = f;

    /// solution
    auto apfi = static_cast<void (*)(int)>(f);      /// overload resolution due to cast
    auto apfd = static_cast<void (*)(double)>(f);   /// overload resolution due to cast

    auto apfi2 = (void (*)(int))f;      /// direct casting
    auto apfd2 = (void (*)(double))f;   /// direct casting;

}

