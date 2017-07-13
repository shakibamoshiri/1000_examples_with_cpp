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
/// noexcept specifier ( since c++ 11 )
// Specifies whether a function will throw exception or not.
//
// syntax:
// noexcept      or noexcept(true)
// noexcept(optional)
//
// 1 Same as noexcept ( true )
// 2 If expression evaluates to true, the function declared to not throw any exception
//
// Explanation
// The noexcept-specification ( just like dynamic exception specification ) can appear
// as part of a lambda ... f m d r m s.
//
//
// If any declaration of a function has a specification that is not 'noexcept(false)'
// other declaration of the same function have to have the same noexcept-specialization.
void f() noexcept;          // f() does not throw
vodi f()                    // error, incompatible exception specification

void g() noexcept(false);   // g() may throw
void g();                   // okay


