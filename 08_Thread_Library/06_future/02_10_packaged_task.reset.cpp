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
/// std::packaged_task::reset

//  Resets the state abandoning the results of previous executions.
//  New shared state is constructed.
//  Equivalent to *this == packaged_task( std::move( f ) ), where
//  f is the stored task.

#include <iostream>
#include <thread>
#include <future>
#include <cmath>



int main(){

    std::packaged_task< int( int, int ) > task(
        []( int a, int b ){
            return std::pow( a, b );
    });

    std::future< int > result = task.get_future();
    task( 2, 9 );
    std::cout << "2 ^ 9 == " << result.get() << '\n';

    task.reset();
    result = task.get_future();
    std::thread task_tr1( std::move( task ), 2, 10 );
    task_tr1.join();
    std::cout << "2 ^ 10 == " << result.get() << '\n';


}

/* output for me:

2 ^ 9 == 512
2 ^ 10 == 1024

*/








