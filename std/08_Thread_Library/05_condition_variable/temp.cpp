/*

    Condition Variable
    ******************


A condition variable is a synchronization primitive that allows multiple
threads to communicate with each other. It allows some number of threads
to wait (possibly with timeout) for notification from another thread that
may proceed.

defined in header <condition_variable>

    cv_status                   Lists the possible results of timed waits on condition variable (enum)
    ---------------------------------------------------------------------------------------

    The scoped enumeration std::cv_status describes whether a timed
    wait returned because of timeout or not.
    std::cv_status is used by the 'wait_for' and 'wait_until' methods
    of std::condition_variable and std::condition_variable_any.

    Member constant
    no_timeout
    timeout
*/

#include <iostream>
#include <thread>
#include <condition_variable>



int main(){}
