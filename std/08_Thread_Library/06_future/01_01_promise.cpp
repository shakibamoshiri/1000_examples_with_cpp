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
/// Example
//  This example shows how std::promise< int > can be used as signals between threads

#include <iostream>
#include <thread>
#include <future>
#include <numeric>
#include <vector>

void accumulate( std::vector< int >::iterator first,
                 std::vector< int >::iterator  last,
                 std::promise< int > accumulate_promise )
{

    int sum = std::accumulate( first, last, 0 );
    accumulate_promise.set_value( sum );    // Notify future
}

int main(){

    std::vector< int > numbers { 1, 2, 3, 4, 5, 6 };
    std::promise< int > accumulate_promise;
    std::future< int > accumulate_future = accumulate_promise.get_future();

    std::thread work_thread( accumulate, numbers.begin(), numbers.end(), std::move( accumulate_promise ) );

    accumulate_future.wait();   // wait for result

    std::cout << "result == " << accumulate_future.get() << '\n';
    work_thread.join();
}

/* output for me:

result == 21

*/








