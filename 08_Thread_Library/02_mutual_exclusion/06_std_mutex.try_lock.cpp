/*
        std::mutex
        **********

The mutex class is a synchronization primitive that can be used
to protect shared data from being simultaneously accessed by multiple thread.

The behavior of a program is undefined if a mutex is destroyed
while still owned by some thread. The mutex class satisfies all
requirement of Mutex and StandardLayoutType.

std::mutex is neither copyable nor movable.

    Member types:
        native_handle_type

    Member functions:
        constructor
        destructor
        operator=

        lock
        try_lock
        unlock

        native_handle

Note:
std::mutex is usually not accessed directly: std::unique_lock and
std::lock_guard are used to manage locking in exception-safe manner.

*/
/// std::mutex::try_lock

//  Tires to look mutex. Returns immediately. On successful lock acquisition
//  return true, otherwise returns false.

#include <iostream>
#include <mutex>

#include <chrono>
#include <thread>

std::chrono::milliseconds interval( 100 );

std::mutex mutex;

int job_shared = 0; // both thread can modify 'job_shared'
                    // mutex will protect this variable

int job_exclusive = 0;  // only one thread can modify 'job_exclusive'
                        // no protected needed

// this thread can modify both 'job_shared' and 'job_exclusive'
void job_1(){

    std::this_thread::sleep_for( interval );        // lets 'job_2' take a place

    while( true ){

        // try to lock mutex to modify 'job_shared'
        if( mutex.try_lock() ){

            std::cout << "job shared ( " << job_shared << " ) \n";
            mutex.unlock();

            return;

        } else {
            // cannot get lock to modify 'job_shared'
            // but there is some other work to do
            ++job_exclusive;

            std::cout << "job_exclusive ( " << job_exclusive << " )\n";

            std::this_thread::sleep_for( interval );
        }
    }
}

// this thread can only modify 'job_shared'
void job_2(){

    mutex.lock();

    std::this_thread::sleep_for( interval * 5 );
    ++job_shared;

    mutex.unlock();

}

int main(){

    std::thread tr1( job_1 );
    std::thread tr2( job_2 );

    tr1.join();
    tr2.join();

}

/* output for me:

job_exclusive ( 1 )
job_exclusive ( 2 )
job_exclusive ( 3 )
job_exclusive ( 4 )
job shared ( 1 )

*/
