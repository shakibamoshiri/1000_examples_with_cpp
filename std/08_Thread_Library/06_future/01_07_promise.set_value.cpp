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
/// std::promise::set_value

//  Stores the 'value' into the shared state and makes the state ready.

#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <cctype>

// This example shows how promise< void > can be used as signals between threads.
int main(){

    std::istringstream iss_numbers { "3 4 1 42 43 -34 -234 -433 34 99 3" };
    std::istringstream iss_letters { " a b sdf 3 39 -3 sd ;?sdf03, ks C" };

    std::vector< int > numbers;
    std::vector< char > letters;
    std::promise< void > numbers_promise,
                         letters_promise;

    std::future< void > numbers_ready = numbers_promise.get_future();
    std::future< void > letters_ready = letters_promise.get_future();

    std::thread value_reader(
        [ & ]{  // capture everything by reference
            // I/O operations
            std::copy( std::istream_iterator< int >{ iss_numbers },
                       std::istream_iterator< int >{ },
                       std::back_inserter( numbers ) );

            // notify for numbers
            numbers_promise.set_value();

            std::copy_if( std::istreambuf_iterator< char >{ iss_letters },
                          std::istreambuf_iterator< char >{ },
                          std::back_inserter( letters ),
                          ::isalpha );

            // notify for letters
            letters_promise.set_value();
        }
    );  // end of thread

    numbers_ready.wait();

    std::sort( numbers.begin(), numbers.end() );

    if( letters_ready.wait_for( std::chrono::seconds( 1 ) )
        == std::future_status::timeout ){

        // output the numbers while letters are being obtained
        for( int temp : numbers ) std::cout << temp << ' ';
        numbers.clear();        // numbers were already printed.
    }

    letters_ready.wait();
    std::sort( letters.begin(), letters.end() );

    // if numbers were already printed, it does nothing
    for( int temp : numbers ) std::cout << temp << ' ';
    std::cout << '\n';

    for( char temp : letters ) std::cout << temp << ' ';
    std::cout << '\n';

    value_reader.join();
}

/* output for me:

-433 -234 -34 1 3 3 4 34 42 43 99
C a b d d d f f k s s s s

*/








