/*

    thread support library
    **********************
Defined in header <future>

    packaged_task
    ************

The class std::packaged_task  wraps any CallAble target (function, lambda expression
bind expression, or another function object) so that it can be invoked asynchronously.
Its return value or expression thrown is stored in a shared state which can be
accessed through std::future object.

    Member function:
        constructor
        destructor
        operator =
        valid
        swap

        get_future
        operator ()
        make_ready_at_thread_exit
        reset

    Non-member function:
        std::swap

    Helper classes
        std::uses_allocator< std::packaged_task >

*/
/// std::packaged_task::packaged_task (constructor)

#include <iostream>
#include <thread>
#include <future>

int fibonacci( int n ){

    if( n < 3 ) return 1;
    else        return fibonacci( n - 1 ) + fibonacci( n - 2 );

}

int main(){

    std::packaged_task< int( int ) > fib_task( fibonacci );

    std::cout << "starting task...\n";
    std::future< int > result = fib_task.get_future();

    std::thread tr1( std::move( fib_task ), 40 );

    std::cout << "waiting for task to finish...\n";
    std::cout << result.get() << '\n';

    std::cout << "task completed\n";

    tr1.join();

}

/* output for me:

starting task...
waiting for task to finish...
102334155
task completed

*/








