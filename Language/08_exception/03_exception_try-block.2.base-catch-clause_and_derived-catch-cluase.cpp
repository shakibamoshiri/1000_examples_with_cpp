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
/// 02 try-block
// Associates one or more exception handlers ( catch-clauses ) with a compound statement
//
// syntax:
// try compound-statement handler-sequence
//
// where hander-sequence is a sequence of one or more handlers, which have the following syntax:
//
// 1 catch ( attribute (optional) type-specifier-sequence declarator ) compound statement
// 2 catch ( attribute (optional) type-specifier-sequence declarator (optional) ) compound statement
// 3 catch ( ... ) compound statement
//
//
//
// NOTES:
// The throw-expression throw NULL: is not matched by a pointer catch clause,
// because the exception object type is int, but throw 'nullper'; is matched by
// any pointer or pointer-to-member catch clause.
//
// If a catch-clause for a derived class is placed after the catch-clause for a
// base class, the derived catch-clause with never be executed.
try {
    func();
} catch ( cosnt std::exception* err ){      // base catch-clause => std::exception

    // will be executed if func() throws std::runtime_error

} catch ( const std::runtime_error& rte ) { // derived catch-clause => std::runtime_error

    // dead code!

}
