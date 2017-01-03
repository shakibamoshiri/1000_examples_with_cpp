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

/// std::thread::swap
//  void swap( thread& other )

//  Exchanges the underlying handles of two thread object.

#include <iostream>
#include <thread>
#include <chrono>

void function_1(){
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
}

void function_2(){
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
}



int main(){

    std::thread tr1( function_1 );
    std::thread tr2( function_2 );

    std::cout << "thread 1 id: " << tr1.get_id() << '\n';
    std::cout << "thread 2 id: " << tr2.get_id() << '\n';

    tr1.swap( tr2 );    // member function

    std::cout << "\nafter tr1.swap( tr2 ):\n";
    std::cout << "thread 1 id: " << tr1.get_id() << '\n';
    std::cout << "thread 2 id: " << tr2.get_id() << '\n';

    std::swap( tr1, tr2 );  // member of algorithm library

    std::cout << "\nafter std::swap( tr1, tr2 ):\n";
    std::cout << "thread 1 id: " << tr1.get_id() << '\n';
    std::cout << "thread 2 id: " << tr2.get_id() << '\n';

    tr1.join();
    tr2.join();

}



/* output:

thread 1 id: 3073829696
thread 2 id: 3065436992

after tr1.swap( tr2 ):
thread 1 id: 3065436992
thread 2 id: 3073829696

after std::swap( tr1, tr2 ):
thread 1 id: 3073829696
thread 2 id: 3065436992


*/
