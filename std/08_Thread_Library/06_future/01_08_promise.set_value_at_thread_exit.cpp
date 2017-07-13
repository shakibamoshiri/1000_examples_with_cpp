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
/// std::promise::set_value_at_thread_exit

//  Stores the 'value' into the shared state without making the
//  state ready immediately. The state is made ready when the
//  current thread exits, after all variables with thread-local
//  storage duration have been destroyed.

#include <iostream>
#include <thread>
#include <future>


using namespace std::literals::chrono_literals;

int main(){

    std::promise< int > p;
    std::future< int >  f = p.get_future();

    std::thread(
        [ p = std::move( p ) ]() mutable {
            std::this_thread::sleep_for( 5s );  // 5 seconds
            p.set_value_at_thread_exit( 9 );
        }
    ).detach();

    std::cout << "waiting... " << std::flush;
    f.wait();
    std::cout << "done\nresult is : " << f.get() << '\n';

}

/* output for me:

waiting... done
result is : 9

*/








