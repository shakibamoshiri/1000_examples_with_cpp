/*
        std::mutex
        **********

The mutex class is a synchronization primitive that can be used
to protect shared data from being simultaneously accessed by multiple thread.

The behavior of a program is undefined if a mutex is destroyed
while still owned by some thread. The mutex class satisfies all
requirement of Mutex and StandardLayoutType.

std::mutex is neither copyable nor movable.

    Member types:
        native_handle_type

    Member functions:
        constructor
        destructor
        operator=

        lock
        try_lock
        unlock

        native_handle

Note:
std::mutex is usually not accessed directly: std::unique_lock and
std::lock_guard are used to manage locking in exception-safe manner.

*/
/// std::mutex

#include <iostream>
#include <mutex>

#include <map>
#include <string>
#include <chrono>
#include <thread>

std::map< std::string, std::string > g_pages;
std::mutex g_pages_mutex;

void save_page( const std::string& url ){

    // simulate a long page fetch
    std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    std::string result = "fake content";

    std::lock_guard< std::mutex > guard( g_pages_mutex );
    g_pages[ url ] = result;

}

int main(){

    std::thread tr1( save_page, "http://first.com" );
    std::thread tr2( save_page, "http://second.com" );

    tr1.join();
    tr2.join();

    // safe to access g_pages without lock now, as the
    // thread are joined
    for( const std::pair< std::string, std::string >& pair : g_pages ){
        std::cout << pair.first << " => " << pair.second << '\n';
    }

}

/* output for me:

http://first.com => fake content
http://second.com => fake content


*/
