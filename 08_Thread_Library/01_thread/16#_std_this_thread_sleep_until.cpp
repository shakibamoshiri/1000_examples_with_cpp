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

/// std::this_thread::sleep_until

//  Blocks the execution of the current thread until specified
//  sleep_time (parameter) has been reached.

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>


int main(){

    std::chrono::time_point< std::chrono::_V2::high_resolution_clock >
    time_now = std::chrono::_V2::high_resolution_clock::now();

    std::time_t current_time = std::time( nullptr );
    std::cout << std::ctime( &current_time );

    std::chrono::time_point< std::chrono::_V2::high_resolution_clock >
    two_second_later = time_now + std::chrono::seconds( 2 );

    std::this_thread::sleep_until( two_second_later );

    current_time = std::time( nullptr );
    std::cout << std::ctime( &current_time );

}

/* output:

Mon Jan  2 13:42:40 2017
Mon Jan  2 13:42:42 2017

*/
