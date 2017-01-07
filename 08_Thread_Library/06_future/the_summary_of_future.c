/*

    std::future
    ***********

The standard library provides facilities to obtain values that are returned and
to catch exceptions that are thrown by asynchronous tasks (i.e. functions launched
in separate threads). These values are communicated in a shared state, in which
the asynchronous task may write its return value or store an exception, and which
may be examined, waited for, and otherwise manipulated by other threads that hold
instances of std::future or std::shared_future that reference that shared state.

Defined in header <future>

promise         stores a value for asynchronous retrieval
packaged_task   packages a function to store its return value for asynchronous retrieval
future          waits for a value that is set asynchronously
shared_future   waits for a value (possibly referenced by other futures) that is set asynchronously
async           runs a function asynchronously (potentially in a new thread) and returns a std::future that will hold the result
launch          specifies the launch policy for std::async
future_status   specifies the results of timed waits performed on std::future and std::shared_future

Future errors:
    future_error    reports an error related to futures or promises
    future_category identifies the future error category
    future_errc     identifies the future error codes

*/
