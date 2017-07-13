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

/// std::this_thread::sleep_for

//  Blocks the execution of the current thread for at least
//  the special sleep_duration (parameter at the function call)


#include <iostream>
#include <thread>
#include <chrono>



int main(){

    using namespace std::literals;

    std::cout << "hello waiter" << '\n';

    std::chrono::time_point< std::chrono::_V2::high_resolution_clock >
    start = std::chrono::_V2::high_resolution_clock::now();

    std::this_thread::sleep_for( 2s );  // 2 seconds

    std::chrono::time_point< std::chrono::_V2::high_resolution_clock >
    end = std::chrono::_V2::high_resolution_clock::now();

    std::chrono::duration< double > elapsed1 = end - start;
    std::cout << "waited for " << elapsed1.count() << " ms\n";

    std::chrono::duration< double, std::milli > elapsed2 = end - start;
    std::cout << "waited for " << elapsed2.count() << " ms\n";

}

/* output:

hello waiter
waited for 2.00026 ms
waited for 2000.26 ms

*/
