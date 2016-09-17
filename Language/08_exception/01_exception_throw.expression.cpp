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
/// 01 throw exception
// Signals an erroneous and execute and error.
// Syntax:
// throw expression
// throw
//
// Explanation
// 1. First, copy-initializes the exception object from expression (this may call the
// move constructor for r-value expression, and the copy / move may be subject to copy
// elision, then transfers control to the exception handler with the matching type whose
// compound statement or member initializer list was most recently entered and not existed
// by this thread of execution.
// 2. Rethrows the currently handled exception.
//
/** The Exception Object **/
// The exception object is a temporary object in unspecified storage that is constructed
// by the 'throw' exception.
// The type of the exception object is the static type of expression whit top-level
// cv-qualifiers removed. (f m d r m s)
//
// Unlike other temporary object, the exception object is considered to be an l-value argument
// when initializing the catch clause parameters, so it can be caught by l-value, reference,
// modified, and rethrown.
//
/** Stack unwinding **/
// (F m d r m s)
//
//
// NOTES:
// where rethrowing exception, the second form must be used to avoid object
// slicing in the ( typical ) case where exception objects use inheritance:
try {
    std::string("abc").substr(10);      // throw std::length_error
} catch ( const std::exception& e ) {
    std::cout<<e.what()<<std::endl;
    throw e;                            // copy-initializes a new exception object of type std::exception
    throw;                              // rethrow the exception object of type std::length_error
}
//
//
// The throw-exception is classified as pr-value exception of type void. Like any other
// exception, it may be a sub-expression in another expression, most commonly in the
// conditional operator:
double f(double d) {
    return d > 1e7 ? throw std::overflow_error("too big") : d;
}
int main(){
    try {
        std::cout<<f(1e10)<<std::endl;
    } catch ( std::overflow_error& e ) {
        std::cout<<e.what()<<std::endl; // output: "too big"
    }
}
