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
/// 03 Function Try-block
// Establishes an exception handler around the body of a function
//
// syntax:
// The function-try block is one of the alternative syntax forms form function
// -body, which is a part of function definition.
// try constructor-initializer (optional) compound-statement handler-sequence
//
// A function-try-block a associate a sequence of catch clauses with the entire
// function body, and with the member initializer list ( if used in a constructor )
// as well.

struct S {
    std::string str;
    S(const std::string& tStr):
        str(tStr) {
            throw;      // it is for test, not correct usage
            std::cout<<"constructor was called..."<<std::endl;
        } catch ( const std::exception& err ) {
            std::cout<<"ERROR: "<<err.what()<<std::endl;
        }
};


int main(){
    S s("Hello Word");  // terminate called without an active exception
                        // Aborted (core dumped)

}
