/*

    thread support library
    **********************
Defined in header <future>

    promise
    *******
The class template std::promise provides a facility to store
a value or an exception that is later acquired asynchronously
via std::future object created by the std::promise object.

    Member function:
        constructor
        destructor
        operator =
        swap

        get_future

        set_value
        set_value_at_thread_exit
        set_exception
        set_exception_at_thread_exit

    Non-member function:
        std::swap( std::promise )

    Helper classes:
        std::uses_allocator< std::promise >

*/
/// std::promise::set_exception

//  Stores the exception pointer 'p' into the shared state and
//  makes the state ready.

#include <iostream>
#include <thread>
#include <future>




int main(){

    std::promise< int > result;

    std::thread tr1(
        [ & ]{
            try {
                // code that may throw
                throw std::runtime_error( "example" );
            } catch ( ... ){
                try {
                    // store anything thrown in the promise
                    result.set_exception( std::current_exception() );
                } catch ( ... ) { } // set_exception() may throw too
            }
        }
    );  // end of thread tr1

    try {
        std::cout << result.get_future().get();
    } catch ( const std::exception& er ){
        std::cout << "exception from the thread: " << er.what() << std::endl;
    }

    tr1.join();


}

/* output for me:

exception from the thread: example

*/








