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
/// std::packaged_task::make_ready_at_thread_exit

//  Calls the stored task with forwarded 'args' as the argument.
//  The return value of the task or any exception thrown by it
//  is stored in the shared state of *this.
//  The shared state is only made ready after the current thread
//  exist and all objects of thread local storage duration are destroyed.

#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <utility>
#include <chrono>


void worker( std::future< void >& output ){

    std::packaged_task< void( bool& ) > my_task{ []( bool& done ){ done = true; } };

    auto result = my_task.get_future();

    bool done = false;

    my_task.make_ready_at_thread_exit( done );  // execute task right away

    std::cout << "worker: done = " << std::boolalpha << done << std::endl;

    auto status = result.wait_for( std::chrono::seconds( 0 ) );
    if( status == std::future_status::timeout ){
        std::cout << "worker: result is not ready yet\n";
    }

    output = std::move( result );

}


int main(){

    std::future< void > result;

    std::thread{ worker, std::ref( result ) }.join();

    auto status = result.wait_for( std::chrono::seconds( 0 ) );
    if( status == std::future_status::ready ){
        std::cout << "main: result is ready\n";
    }

}

/* output for me:

worker: done = true
worker: result is not ready yet
main: result is ready

*/








