/*
            Error Handling
            **************

1.  Exception Handling:
    The header <exception> provides several classes and function related
    to exception handling in C++ program. (defined in header <exception>)

    1.3 handling of exception specification violation
        > unexpected            : (deprecated since C++11)
        > bad_exception         : exception throw when dynamic exception specification is violated, if possible
        > unexpected_handler    : (deprecated since C++11)
        > set_unexpected        : (deprecated since C++11)
        > get_unexpected        : (deprecated since C++11)

*/
/// std::bad_exception
//  It is the type of the exception thrown by the c++
//  runtime.

#include <iostream>
#include <exception>
#include <stdexcept>

void may_unexp (){ throw; }

void test () throw( std::bad_exception ) { throw std::runtime_error( "the test function" ); }


int main(){

    {
        std::set_unexpected( may_unexp );

        try { test(); }
        catch (const std::bad_exception& er){ std::cerr << "caught bad_exception: " << er.what() << std::endl; }

    }
}
