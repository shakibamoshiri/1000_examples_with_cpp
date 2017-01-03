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

/// std::this_thread::yield

//  Provides a hint implementation to reschedule the execution
//  of threads, allowing other threads to tun.

#include <iostream>
#include <thread>
#include <chrono>

// "busy sleep" while suggesting that other thread run
// for a small amount of time
void little_sleep( std::chrono::microseconds us ){

    std::chrono::time_point< std::chrono::high_resolution_clock >
    start = std::chrono::high_resolution_clock::now();

    auto end = start + us;

    do{
        std::this_thread::yield;
    } while( std::chrono::high_resolution_clock::now() < end );

}


int main(){

    std::chrono::time_point< std::chrono::_V2::high_resolution_clock >
    start = std::chrono::_V2::high_resolution_clock::now();

    little_sleep( std::chrono::milliseconds( 100 ) );

    std::chrono::duration< long double > // or just double
    elapsed = std::chrono::_V2::high_resolution_clock::now() - start;

    std::cout << "waited for: "
              << std::chrono::duration_cast< std::chrono::microseconds >( elapsed ).count()
              << " milliseconds\n";

}

/* output:

waited for: 100000 millisecond
*/
