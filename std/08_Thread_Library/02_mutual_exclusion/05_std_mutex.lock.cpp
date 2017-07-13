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
/// std::mutex::lock

//  Locks the mutex. If another thread has already locked the mutex
//  a call to lock will block execution until the lock is acquired.

//  If lock() is called by a thread that already owns the mutex, the
//  behavior is undefined: the program may deadlock

//  NOTE:
//  lock() is usually not called directly: std::unique_lock and
//  std::lock_guard are used to manage exclusive locking.


#include <iostream>
#include <mutex>

#include <chrono>
#include <thread>

int g_num = 0;      // protected by g_num_mutex
std::mutex g_num_mutex;

void show_increment( int id ){

    for( int iterator = 0; iterator < 3; ++iterator ){
        g_num_mutex.lock();
        ++g_num;
        std::cout << id << " => " << g_num << '\n';
        g_num_mutex.unlock();

        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    }

}

int main(){

    std::thread tr1( show_increment, 0 );
    std::thread tr2( show_increment, 1 );

    tr1.join();
    tr2.join();

}

/* output for me:

0 => 1
1 => 2
0 => 3
1 => 4
0 => 5
1 => 6

*/
