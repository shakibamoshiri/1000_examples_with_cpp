/*
        Generic Mutex Algorithm
        ***********************

try_lock        attempts to obtain ownership of mutexes via repeated calls to try_lock
lock            locks specified mutexes, blocks if any are unavailable

Call once:

once_flag       helper object to ensure that call_once invokes the function only once
call_once       invokes a function only once even if called from multiple threads
*/

/// std::try_lock

//  Tries to lock each of the given Lockable objects lock1, lock2, ..., lockN
//  by calling try_lock in order beginning with the first.

//  return value:
//  1 on success, or 0-based index value of the object that failed to lock

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include <functional>

int main()
{
    int foo_count = 0;
    std::mutex foo_count_mutex;
    int bar_count = 0;
    std::mutex bar_count_mutex;
    int overall_count = 0;
    bool done = false;
    std::mutex done_mutex;

    auto increment = [](int &counter, std::mutex &m,  const char *desc) {
        for (int i = 0; i < 10; ++i) {
            std::unique_lock<std::mutex> lock(m);
            ++counter;
            std::cout << desc << ": " << counter << '\n';
            lock.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    };

    std::thread increment_foo(increment, std::ref(foo_count),
        std::ref(foo_count_mutex), "foo");
    std::thread increment_bar(increment, std::ref(bar_count),
        std::ref(bar_count_mutex), "bar");

    std::thread update_overall([&]() {
        done_mutex.lock();
        while (!done) {
            done_mutex.unlock();
            int result = std::try_lock(foo_count_mutex, bar_count_mutex);
            if (result == -1) {
                overall_count += foo_count + bar_count;
                foo_count = 0;
                bar_count = 0;
                std::cout << "overall: " << overall_count << '\n';
                foo_count_mutex.unlock();
                bar_count_mutex.unlock();
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
            done_mutex.lock();
        }
        done_mutex.unlock();
    });

    increment_foo.join();
    increment_bar.join();
    done_mutex.lock();
    done = true;
    done_mutex.unlock();
    update_overall.join();

    std::cout << "Done processing\n"
              << "foo: " << foo_count << '\n'
              << "bar: " << bar_count << '\n'
              << "overall: " << overall_count << '\n';
}

/*

overall: 0
bar: 1
foo: 1
foo: 2
bar: 2
overall: 4
foo: 1
bar: 1
foo: 2
bar: 2
overall: 8
foo: 1
bar: 1
foo: 2
bar: 2
foo: 3
bar: 3
foo: 4
bar: 4
foo: 5
bar: 5
overall: 18
foo: 1
bar: 1
Done processing
foo: 1
bar: 1
overall: 18

*/
