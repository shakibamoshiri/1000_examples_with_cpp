/*
        Generic Mutex Algorithm
        ***********************

try_lock        attempts to obtain ownership of mutexes via repeated calls to try_lock
lock            locks specified mutexes, blocks if any are unavailable

Call once:

once_flag       helper object to ensure that call_once invokes the function only once
call_once       invokes a function only once even if called from multiple threads
*/
