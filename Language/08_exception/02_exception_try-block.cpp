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
// 1 Catch-clause that declares a named formal parameter
    try { /* something */ } catch (const exception& e) { /* something */ }
//
// 2 Catch-clause that declares an unnamed parameter
    try { /* something */ } catch (const exception&) { /* something */ }
//
// 3 Catch-all handler, which is activated for any exception
    try { /* something */ } catch (...) { /* something */ } // ( ... )  it names ellipsis ( or three dots )
//
//
// NOTE:
// The try-block is a statement, and as such, can appear anywhere a statement can appear.
try {
    function();
} catch ( const std::overflow_error& ofe ){

    // this executes if function() throws std::overflow_error ( same type rule )

} catch ( const std::runtime_error& rte ){

    // this executes if function() throws std::underflow_error ( base class rule )

} catch ( const std::exception& err) {

    // this executes if function() throws std::logical_error ( base class rule )

} catch ( ... ) {

    // this executes if function() throws std::string or int or any other unrelated type

}

