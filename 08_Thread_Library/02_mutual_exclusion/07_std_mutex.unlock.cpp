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
/// std::mutex::unlock

//  Unlocks the mutex.
//  The mutex must be locked by the current thread of execution, otherwise
//  the behavior is undefined.

//  NTEE:
//  unlock() is usually not called directly: std::unique_lock
//  and std::lock_guard are used to manage exclusive locking.

#include <iostream>
#include <mutex>



// this example shows lock, try_lock and unlock in action:
int main(){

    std::mutex mutex;

    if( mutex.try_lock() ){     // it returns a bool

        std::cout << "first try_lock successful\n";

    } else {

        std::cout << "first try_lock NOT successful\n";

        return 0;

    }

    mutex.unlock();
    mutex.lock();

    if( mutex.try_lock() ){     // it returns a bool

        std::cout << "first try_lock successful\n";

    } else {

        std::cout << "first try_lock NOT successful\n";

        return 0;

    }

    mutex.lock();       // trying to lock an already-locked std::mutex will
                        // block program exclusion, so we will hang here

}

/* output for me:( may be something else for you )

first try_lock successful
first try_lock NOT successful

*/
