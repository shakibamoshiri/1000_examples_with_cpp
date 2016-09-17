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
// It cannot appear in a typedef or type alias declaration

void f() noexcept;              // the function f() does not throw

void f1() noexcept(true);       // the function f1() does not throw

void (*fp)() noexcept(false);   // fp points to function that may throw

void f2 (void pfa() noexcept);  // f2 takes a pointer to function that does not throw

typedef int {*pf)() noexcept;   // error

// The noexcept-specification is not a part of the function type.
//
// The noexcept-specification is a part of the function type and may appear
// as part of any function declaration ( since c++ 17 )
