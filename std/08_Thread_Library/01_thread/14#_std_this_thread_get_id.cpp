/*
        std::thread
        ***********

defined in header <thread>

The class 'thread' represent a single thread of execution.
Threads allows multiple pieces of code to run asynchronously
and simultaneously.

NOTE: std::thread is not CopyConstructible or CopyAssignable.
It is MoveConstructible and MoveAssignable.

    std::this_thread::yield
    std::this_thread::get_id
    std::this_thread::sleep_for
    std::this_thread::sleep_until

*/

/// std::this_thread::get_id

//  Returns the id of the current thread.


#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex g_display_mutex;

void function(){

    std::thread::id this_id = std::this_thread::get_id();

    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();

    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );

}


int main(){

    std::thread tr1( function );
    std::thread tr2( function );

    tr1.join();
    tr2.join();

}

/* output:

thread 3065711424 sleeping...
thread 3074104128 sleeping...


*/
