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

/// std::thread::joinable

//  Checks if the thread object identifies an active thread of
//  execution. Specifically, returns true if get_id() != std::thread::id.
//  So a default constructed thread in not joinable.

//  A thread that has finished executing code, but has not yet
//  been joined, is still considered as an active thread of
//  execution and is therefore joinable


#include <iostream>
#include <thread>
#include <chrono>


void f(){
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
}

int main(){



    std::boolalpha( std::cout );

    std::thread tr1;
    std::cout << "before starting, joinable: " << tr1.joinable() << '\n';

    tr1 = std::thread( f ); // assigns f() to tr1
    std::cout << "after starting, joinable:  " << tr1.joinable() << '\n';

    tr1.join();
    std::cout << "after joining,  joinable:  " << tr1.joinable() << '\n';


}



/* output:

before starting, joinable: false
after starting, joinable:  true
after joining,  joinable:  false

*/
