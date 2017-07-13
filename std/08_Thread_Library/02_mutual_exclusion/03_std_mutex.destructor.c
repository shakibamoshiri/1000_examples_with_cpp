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
/// std::mutex
/// constructor,
/// operator = ( is deleted )
//  mutex( const mutex& ) = delete

/// destructor
//  The behavior is undefined if the mutex is owned by any thread
//  or if any thread terminates while holding any ownership of the mutex.

#include <iostream>
#include <mutex>

#include <map>
#include <string>
#include <chrono>
#include <thread>


int main(){

    // has no example

}

/* output for me:



*/
