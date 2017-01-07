/*

    Condition Variable
    ******************


A condition variable is a synchronization primitive that allows multiple
threads to communicate with each other. It allows some number of threads
to wait (possibly with timeout) for notification from another thread that
may proceed.

defined in header <condition_variable>

    condition_variable          provides a condition variable associated with a std::unique_lock
    --------------------------------------------------------------------------------------------

    The 'condition_variable' class is a synchronization primitive that can be used to
    block a thread, multiple thread at the same time, until another thread both modifies
    a shared variable (the condition), and notifies the 'condition_variable'.

    Member type:
        native_handle_type

    Member function:
        constructor
        destructor
        operator = [ deleted ]

        notify_one
        notify_all

        wait
        wait_for
        wait_until

        native_handle

*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>

std::mutex mutex;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread(){

    // wait until main() send data
    std::unique_lock< std::mutex > lk( mutex );
    cv.wait( lk, []{ return ready; } );

    // after the wait, we own the lock
    std::cout << "worker thread is processing data\n";
    data += "after processing";

    // send data back to main()
    processed = true;
    std::cout << "worker thread signals data processing completed\n";

    // manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for  details)
    lk.unlock();
    cv.notify_one();

}

// 'condition_variable' is used in combination with a std::mutex
//  to facilitate inter-thread communication
int main(){

    std::thread worker( worker_thread );

    data = "example data";

    // send data to the worker_thread
    {
        std::lock_guard< std::mutex > lk( mutex );
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }

    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock< std::mutex > lk( mutex );
        cv.wait( lk, []{ return processed; } );
    }

    std::cout << "back in main(), data == " << data << '\n';

    worker.join();

}


/*

main() signals data ready for processing
worker thread is processing data
worker thread signals data processing completed
back in main(), data == example dataafter processing


*/







