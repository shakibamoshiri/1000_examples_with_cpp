/*

A review of thread library

*/

#include <iostream>
#include <vector>
#include <atomic>
#include <thread>

std::atomic< int > global_counter( 0 );

void increase_global( const int N ){
    for( int counter = 0; counter < N; ++counter ){
        ++global_counter;
    }
}
void increase_reference( std::atomic< int >& var, const int N ){
    for( int counter = 0; counter < N; ++counter ){
        ++var;
    }
}

struct C : std::atomic< int > {
    C(): std::atomic< int >( 0 )
    {}

    void increase_member( const int N ){
        for( int counter = 0; counter < N; ++counter ){
            fetch_add( 1 );
        }
    }
};

int main( ){

    std::vector< std::thread > threads;

    std::cout << "increase global counter with 10 threads...\n";
    for( short index = 0; index < 10; ++index ){
        threads.push_back( std::thread( increase_global, 1000 ) );
    }

    std::cout << "increase counter atm with 10 threads using reference...\n";
    std::atomic< int > atm( 0 );
    for( short index = 0; index < 10; ++index ){
        threads.push_back( std::thread( increase_reference, std::ref( atm ), 1000 ) );
    }

    std::cout << "increase counter( obj ) with 10 threads using member-function...\n";
    C obj;
    for( short index = 0; index < 10; ++index ){
        threads.push_back( std::thread( &C::increase_member, std::ref( obj ), 1000 ) );
    }

    std::cout << "synchronizing all threads...\n";
    for( std::thread & vec : threads ){
        vec.join();
    }

    std::cout << "global counter: " << global_counter << '\n';
    std::cout << "atm           : " << atm << '\n';
    std::cout << "obj           : " << obj << '\n';



}

/* output

increase global counter with 10 threads...
increase counter atm with 10 threads using reference...
increase counter( obj ) with 10 threads using member-function...
synchronizing all threads...
global counter: 10000
atm           : 10000
obj           : 10000


*/
