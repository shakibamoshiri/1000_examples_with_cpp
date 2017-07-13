/*

    Condition Variable
    ******************


A condition variable is a synchronization primitive that allows multiple
threads to communicate with each other. It allows some number of threads
to wait (possibly with timeout) for notification from another thread that
may proceed.

defined in header <condition_variable>

    condition_variable          provides a condition variable associated with a std::unique_lock
    condition_variable_any      provides a condition variable associated with any lock type
    notify_all_at_thread_exit   schedules a call to 'notify_all' to be invoked when this thread is completely finished
    cv_status                   Lists the possible results of timed waits on condition variable (enum)

*/
