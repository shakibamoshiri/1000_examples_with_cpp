/*

    Condition Variable
    ******************


A condition variable is a synchronization primitive that allows multiple
threads to communicate with each other. It allows some number of threads
to wait (possibly with timeout) for notification from another thread that
may proceed.

defined in header <condition_variable>

    condition_variable_any      provides a condition variable associated with any lock type
    ---------------------------------------------------------------------------------------

    The 'condition_variable_any' class in generalization of std::condition_variable. Whereas
    std::condition_variable works only on std::unique_lock< std::mutex >, 'condition_variable_any'
    can operate on any used-defined lock that meets the BasicLockable requirement.

    Member function:
        constructor
        destructor
        operator = [ deleted ]

        notify_one
        notify_all

        wait
        wait_for
        wait_until


*/

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>


int main(){

    // has no example

}


/*



*/







