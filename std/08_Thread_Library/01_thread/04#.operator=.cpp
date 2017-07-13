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

/// std::thread::operator = ( assignment )
//  thread& operator = ( thread&& other );  //since C++11

//  After this call, this->get_id() is equal to the value of
//  of other. get_id() prior to the call, and other no longer
//  represents a thread of execution.


#include <iostream>
#include <thread>


void f(){}

int main(){



    std::boolalpha( std::cout );

    std::thread tr1( f );   // okay it is a thread

    std::cout << tr1.get_id() << '\n';

    if( tr1.joinable() == true ) std::cout << "tr1 is joinable\n";

    std::thread tr2 = std::move( tr1 );

    std::cout << tr2.get_id() << '\n';

    tr2.join();


}



/* output:

3073719104
tr1 is joinable
3073719104

*/
