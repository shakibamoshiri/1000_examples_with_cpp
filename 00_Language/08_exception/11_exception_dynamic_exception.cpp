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

void f() throw(int);            // okay, function declaration
void (*fp)() throw(int);        // okay, pointer to function declaration
void g(void pfa() throw(int));  // okay, pointer to function parameter declaration
typedef int (*pf()() throw(int);    // error, typedef declaration

// Explanation
// If a function is declared with type T listed in its exception specification,
// the function may throw exception of that type or a type derived form it.
//
//
// Potential exception
// F m d r m s.
