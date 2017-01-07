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
/// std::packaged_task

#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <cmath>

// unique function to avoid disambiguating the std::pow overload set
int f( int x, int y ){ return std::pow( x, y ); }

void task_lambda(){

    std::packaged_task< int( int, int ) > task(
        []( int a, int b ){
            return std::pow( a, b );
        }
    );

    std::future< int > result = task.get_future();
    task( 2, 9 );
    std::cout << "task_lambda:\t" << result.get() << '\n';

}


void task_bind(){

    std::packaged_task< int() > task( std::bind( f, 2, 11 ) );
    std::future< int > result = task.get_future();

    task();

    std::cout << "task_bind:\t" << result.get() << '\n';

}

void task_thread(){

    std::packaged_task< int( int, int ) > task( f );
    std::future< int > result = task.get_future();

    std::thread task_tr( std::move( task ), 2, 10 );
    task_tr.join();

    std::cout << "task_thread:\t" << result.get() << '\n';

}

int main(){

    task_lambda();
    task_bind();
    task_thread();

}

/* output for me:

task_lambda:    512
task_bind:      2048
task_thread:    1024

*/








