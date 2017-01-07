/*

    thread support library
    **********************
Defined in header <future>

    std::future_error
    ******************

The class std::future_error defines an exception object that is
thrown on failure by the functions in the thread library that deal
with asynchronous execution and shared stats ( std::future, std::promise, etc. )
Similar to std::system_error, this exception carries on error code
compatible with std::error_code

    Member function:
        constructor
        code
        what

    Inherited from std::logic_error

    Inherited from std::exception


*/
/// std::future_error

#include <iostream>
#include <future>


int main(){

    std::future< int > empty;
    try {
        int n = empty.get();    // the behavior is undefined, but some implementation throw std::future_error
    } catch( const std::future_error& fer ){
        std::cout << fer.code() << '\n' << fer.what() << std::endl;
    }


}

/* output for me:

future:3
std::future_error: No associated state

*/








