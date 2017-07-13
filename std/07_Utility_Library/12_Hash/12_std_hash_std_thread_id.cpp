/*
        std::hash
        *********

defined in header <functional>

The hash template defines a function object that implements a hash
function, Instances of this function object satisfy Hash.
(for more detail see the main website)

    Member Type:
        argument_type       key
        result_type         std::size_t

    Member Function:
        constructor
        operator

*/
/// std::hash for std::thread

//  the template specialization of std::hash for the std::thread::id
//  class allows users to obtain hashes of the identifiers of threads.


#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std::literals::chrono_literals;

void function()
{ std::this_thread::sleep_for( 10ms ); }


int main(){

    std::vector< std::thread > vt;

    for( int number = 0; number < 4; ++number) vt.emplace_back( function );

    std::hash< std::thread::id > hash_of_thread;

    for( std::thread& tr : vt ){
        std::cout << "thread " << tr.get_id() << " hashes to " << hash_of_thread( tr.get_id() ) << '\n';
        tr.join();
    }

}

/* output for me

thread 3074026304 hashes to 1060767719
thread 3065633600 hashes to 4096655672
thread 3057240896 hashes to 3588848867
thread 3048848192 hashes to 1711632055

*/
