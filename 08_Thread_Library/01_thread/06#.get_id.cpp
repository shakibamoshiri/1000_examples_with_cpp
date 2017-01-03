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

/// std::thread get_id()
//  thread::id get_id() const;

//  Returns a value of std::thread::id identifying the thread
//  associated with *this.


#include <iostream>
#include <thread>
#include <chrono>


void f(){
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
}

int main(){

    std::thread tr1( f );
    std::thread::id tr1_id = tr1.get_id();

    std::thread tr2( f );
    std::thread::id tr2_id = tr2.get_id();

    std::cout << "tr1's id is: " << tr1_id << '\n';
    std::cout << "tr2's id is: " << tr2_id << '\n';

    tr1.join();
    tr2.join();



}



/* output:

tr1's id is: 3073542976
tr2's id is: 3065150272
*/
