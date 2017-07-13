/*

    thread support library
    **********************
Defined in header <future>

    std::future
    ***********

The class template std::future provides a mechanism to access the
result of asynchronous operations.
NOTE:
the std::future references shared state that is not shared with any
other asynchronous return objects ( as opposite to std::shared_future )

    Member function:
        constructor
        destructor
        operator =
        share

        get

        valid
        wait
        wait_for
        wait_until

*/
/// std::future::wait_for

//  Waits for the result to become available. Blocks until
//  specified timeout_duration has elapsed or the result
//  become available, whichever comes first. Returns value
//  identifies the state of the result.
//  A steady clock is used to measure the duration.


#include <iostream>
#include <thread>
#include <future>
#include <chrono>



int main(){

    std::future< int > future(
        std::async(
            std::launch::async,
            []{ std::this_thread::sleep_for( std::chrono::seconds( 3 ) ); return 8; }
        )
    );

    std::cout << "waiting...\n";
    std::future_status status;
    do {
        status = future.wait_for( std::chrono::seconds( 1 ) );
        if( status == std::future_status::deferred ){
            std::cout << "deferred\n";
        } else if( status == std::future_status::timeout ){
            std::cout << "timeout\n";
        } else if( status == std::future_status::ready ){
            std::cout << "ready\n";
        }
    } while( status != std::future_status::ready );

    std::cout << "result is: " << future.get() << '\n';
}

/* output for me:

waiting...
timeout
timeout
ready
result is: 8

*/








