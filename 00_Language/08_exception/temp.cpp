/*
Exception:
    01
    02 try-block
    03 function-try-block
    04 noexcept specifier ( since c++11 )

    05 noexcept operator  ( since c++11 )

    06 dynamic exception specifier

    For More Detail Read Main Site = f m d r m s
*/
#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>
/// dynamic exception specification
// Lists exceptions that a function might directly or indirectly throw.
// syntax:
// throw ( typeid, typeid, ... ) ( deprecated )
// This specification may appear  only on lambda-declarator on on a function
// declarator that is the top-level ( until c++17 ) declarator of a function,
// variable, or non-static data member, whose type is a function type, a pointer
// to function type, a reference to function type, a pointer to member function type.
// It may appear on the declarator of a parameter or on the declarator of a return type.
//
//
// Example


class X {};
class Y {};
class Z : public X {};
class W {};

void f () throw(X,Y) {
    int n=0;
    if (n) throw X();       // okay
    if (n) throw Z();       // also okay
    throw W();              // will call std::unexpected()
}

int main(){
    std::set_unexpected( [] {
                        std::cout<<"That was unexpected\n";
                        std::abort();
    });
    f();
}
