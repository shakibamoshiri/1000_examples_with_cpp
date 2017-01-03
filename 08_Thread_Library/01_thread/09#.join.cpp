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

/// std::thread::join

//  Blocks the current thread until the thread identified
//  by *this finishes its execution.

//  postcondition:
//  joinable is false


#include <iostream>
#include <thread>
#include <chrono>

void help_1(){
    // simulate expensive operation
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
}

void help_2(){
    // simulate expensive operation
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
}




int main(){

    std::cout << "starting first helper function...\n";
    std::thread tr1( help_1 );

    std::cout << "starting second helper function...\n";
    std::thread tr2( help_2 );

    std::cout << "waiting for helper function to finish...\n";

    tr1.join();
    tr2.join();

    std::cout << "done!\n";

}



/* output:

starting first helper function...
starting second helper function...
waiting for helper function to finish...
done!

*/
