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
#include <utility>
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
// Potential exception
// F m d r m s.

void f() throw(int);        // f()'s set is "int"
void g();                   // g()'s set is "any"
struct A { A(); };          // "new A"'s set is "any"
struct B { B() noexcept; }; // "B()"'s  set is empty
struct D { D() throw(double);       // new D's set is "double, any"

//  A implicitly-declared member function ( and inheriting constructions ) have
// exception specifications, selected as following:
//      if the set of potential exception contains "any", the implicit exception
//      is noexcept(false).
//      Otherwise, if the set of potential exception is not empty, the implicit
//      exception specification lists every type from the set.
//      Otherwise, the implicit exception specification is noexcept(true) and the
//      function type is "noexcept function".

struct A {
    A (int = A(5), 0) noexcept;
    A (const A&) throw();
    A (A&&)      throw();
    ~A()         throw();
};
struct B {
    B() throw();
    B(const B&) = default;      // exception specification is "noexcept(true)"
    B(B&&, int = (throw Y(), 0) throw(Y) noexcept;
    ~B() throw(Y);
};

int n = 7;

struct D : public A, public B {
    int* p =new (std::nothrow) int[n];

    // D has the following implicitly-declared members:
    // D::D() throw(X, std::bad_array_new_length);
    // D::D(const D&) noexcept(true);
    // D::D(D&&) throw(Y);
    // D::~D() throw(X , Y);
};
