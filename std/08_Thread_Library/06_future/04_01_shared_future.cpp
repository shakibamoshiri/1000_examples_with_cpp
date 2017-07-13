/*

    thread support library
    **********************
Defined in header <future>

    std::shared_future
    ***********
The class template std::shared_future provides a mechanism to access
the result of asynchronous operations, similar to std::future, except
that multiple threads are allowed to wait for the same shared status.
Unlike std::future, which is only movable (so only one instance can
refer to any particular asynchronous result), std::shared_future is
copyable and multiple shared future objects may refer to the same state.

*/
/// std::shared_future

#include <iostream>
#include <future>
#include <chrono>


// Example
// A shared_future may be used to signal multiple thread
// simultaneously, similar to std::condition_variable::notify_all()
int main(){

    std::promise< void > ready_promise,
                         t1_ready_promise,
                         t2_ready_promise;
    std::shared_future< void > ready_future( ready_promise.get_future() );

    std::chrono::time_point< std::chrono::_V2::high_resolution_clock > start;

    auto function_1 = [ &, ready_future ]() -> std::chrono::duration< double, std::milli > {
        t1_ready_promise.set_value();
        ready_future.wait();        // waits for the signal form main
        return std::chrono::_V2::high_resolution_clock::now() - start;
    };

    auto function_2 = [ &, ready_future ]() -> std::chrono::duration< double, std::milli > {
        t2_ready_promise.set_value();
        ready_future.wait();        // waits for the signal form main
        return std::chrono::_V2::high_resolution_clock::now() - start;
    };

    auto result_1 = std::async( std::launch::async, function_1 );
    auto result_2 = std::async( std::launch::async, function_2 );

    // wait for the threads to become ready
    t1_ready_promise.get_future().wait();
    t2_ready_promise.get_future().wait();

    // the threads are ready, start the clock
    start = std::chrono::_V2::high_resolution_clock::now();

    // signal the threads to tgo
    ready_promise.set_value();

    std::cout << "thread 1 received the signal "
              << result_1.get().count() << " ms after start\n"
              << "thread 2 received the signal "
              << result_2.get().count() << " ms after start\n";



}

/* output for me:

thread 1 received the signal 0.173576 ms after start
thread 2 received the signal 0.240975 ms after starts

*/








