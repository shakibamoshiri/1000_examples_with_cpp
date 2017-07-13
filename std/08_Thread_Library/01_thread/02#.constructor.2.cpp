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

/// std::thread::thread ( constructor )

//  constructs a new object

// note the thread( const thread& ) = delete

//  Any exceptions thrown during evaluation and copying/moving
//  of the assignment are thrown in the current thread, not the
//  new thread.

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <functional>
#include <utility>

void f1( int temp ){

    for( int iterator = 0; iterator < 5; ++iterator ){

        std::cout << "thread 1 executing...\n";
        ++temp;
        std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

    }

}

void f2( int& temp ){

    for( int iterator = 0; iterator < 5; ++iterator ){

        std::cout << "thread 2 executing...\n";
        ++temp;
        std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

    }

}

int main(){

    int number = 0;

    std::thread tr1;                            // tr1 is not a thread
    std::thread tr2( f1, number + 1 );          // pass by value
    std::thread tr3( f2, std::ref( number ) );  // pass by reference
    std::thread tr4( std::move( tr3 ) );         // tr4 is now running f2(). and tr3 is not longer a thread

    tr2.join();
    tr4.join();

    std::cout << "final value of number is: "
              << number << '\n';

}



/* output:

thread 2 executing...
thread 1 executing...
thread 2 executing...
thread 1 executing...
thread 2 executing...
thread 1 executing...
thread 2 executing...
thread 1 executing...
thread 2 executing...
thread 1 executing...
final value of number is: 5

*/
