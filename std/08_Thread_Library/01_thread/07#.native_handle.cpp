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

/// std::thread::native_handle

//  returns the implementation defined underlying thread handle.


#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <cstring>
#include <pthread.h>

std::mutex iomutex;

void f( int number ){
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );

    sched_param sch;
    int policy;
    pthread_getschedparam( pthread_self(), &policy, &sch );
    std::lock_guard< std::mutex > lk( iomutex );
    std::cout << "thread: " << number << " is executing at priority "
              << sch.sched_priority << '\n';
}

// uses native_handle to enable realtime scheduling of C++ threads on a POSIX system.
int main(){

    std::thread tr1( f, 1 ),
                tr2( f, 2 );

    sched_param sch;
    int policy;
    pthread_getschedparam( tr1.native_handle(), &policy, &sch );
    sch.sched_priority = 20;

    if( pthread_setschedparam( tr1.native_handle(), SCHED_FIFO, &sch ) ){
        std::cout << "failed to setschedparam: "
                  << std::strerror( errno )
                  << '\n';
    }

    tr1.join();
    tr2.join();
}



/* output:

failed to setschedparam: Operation not permitted
thread: 2 is executing at priority 0
thread: 1 is executing at priority 0
*/
