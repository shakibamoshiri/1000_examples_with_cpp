/*
        std::thread
        ***********

defined in header <thread>

The class 'thread' represent a single thread of execution.
Threads allows multiple pieces of code to run asynchronously
and simultaneously.

NOTE: std::thread is not CopyConstructible or CopyAssignable.
It is MoveConstructible and MoveAssignable.

    Member type:
        native_handle_type          implementation-defined

    Member classes:
        id                          represents the id of the thread

    Member function:
        constructor                 constructs a new thread
        destructor                  destructs the thread object, underlying thread must be joined or detached
        operator =                  move the thread object

        joinable                    checks whether the thread is joinable, i.e. potentially running in parallel context
        get_id                      returns the id of the thread
        native_handle               returns the underlying implementation-defined thread handle
        hardware_concurrency        returns the number of concurrent threads supported by the implementation

        join                        waits for a thread to finish its execution
        detach                      permits the thread to execute independently from the thread handle
        swap                        swap

    Non-member function:
        std::swap                   specialized the std::swap algorithm

*/

/// std::thread::detach ( detach means separate something from something that was attached to. opposite attach )

//  Separates the thread of execution form the thread object.
//  Allows execution to continue independently. Any allocated
//  resources will be free one the thread exits.
//  After calling 'detach' *this is no longer owns any thread.

#include <iostream>
#include <thread>
#include <chrono>

void independent_thread(){
    std::cout << "starting concurrent thread.\n";
    std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    std::cout << "exiting concurrent  thread.\n";
}

void thread_caller(){
    std::cout << "starting thread caller.\n";
    std::thread tr1( independent_thread );
    tr1.detach();

    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    std::cout << "exiting thread caller.\n";
}


int main(){

    thread_caller();
    std::this_thread::sleep_for( std::chrono::seconds( 5 ) );

}



/* output:

starting thread caller.
starting concurrent thread.
exiting thread caller.
exiting concurrent  thread.


*/
