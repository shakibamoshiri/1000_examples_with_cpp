/*

A review of thread library

*/
/// std::thread::get_id
//  Gets thread id

#include <iostream>
#include <chrono>
#include <thread>

std::thread::id main_thread = std::this_thread::get_id();

void is_main_thread(){
    if( main_thread == std::this_thread::get_id() ){
        std::cout << "this is the main thread\n";
    } else {
        std::cout << "this is not the main thread\n";
    }
}

int main( ){

    is_main_thread();                       // this is the main thread

    std::thread ( is_main_thread ).join();  // this is not the main thread

}

/* output

this is the main thread
this is not the main thread

Process returned 0 (0x0)   execution time : 0.014 s
Press ENTER to continue.


*/
