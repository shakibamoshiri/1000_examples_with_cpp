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

void thread_one( int& one ){
    one += 10;
}

void thread_two( int& two ){
    two += 10;
}





int main(){

    int number1 = 0;
    int number2 = 0;

    std::thread tr1( thread_one, std::ref( number1 ) );
    std::thread tr2( thread_two, std::ref( number2 ) );
    tr1.join();
    tr2.join();

    std::cout << "the threads was done\n";

    std::cout << ( number1 + number2 ) << '\n';

}



/* output:


*/
