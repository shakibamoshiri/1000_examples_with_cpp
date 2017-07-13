/*
        Generic Mutex Algorithm
        ***********************

try_lock        attempts to obtain ownership of mutexes via repeated calls to try_lock
lock            locks specified mutexes, blocks if any are unavailable

Call once:

once_flag       helper object to ensure that call_once invokes the function only once
call_once       invokes a function only once even if called from multiple threads
*/

/// std::call_once

//  Executes the Callable object 'f' exactly once, even if called
//  from several threads.

#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag_1, flag_2;

void simple_do_once(){
    std::call_once( flag_1, [](){ std::cout << "simple example: called once\n"; } );
}

void may_throw( bool do_throw ){
    if( do_throw ){
        std::cout << "throw: call_once will retry\n";   // this may appear more than once
        throw std::exception();
    }
    std::cout << "did not throw, call_once will not attempt again\n";   // guaranteed once
}

void do_once( bool do_throw ){
    try {
        std::call_once( flag_2, may_throw, do_throw );
    } catch ( ... ){ }
}

int main(){

    std::thread tr1( simple_do_once );
    std::thread tr2( simple_do_once );
    std::thread tr3( simple_do_once );
    std::thread tr4( simple_do_once );

    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();

    std::thread tr11( do_once, true );
    std::thread tr22( do_once, true );
    std::thread tr33( do_once, false );
    std::thread tr44( do_once, true );

    tr11.join();
    tr22.join();
    tr33.join();
    tr44.join();

}

/*
simple example: called once
throw: call_once will retry

^C
*/
