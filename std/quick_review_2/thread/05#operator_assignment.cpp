/*

A review of thread library

*/
/// std::thread operator assignment =
//

#include <iostream>
#include <chrono>
#include <thread>

void pause_thread( const int N ){
    std::this_thread::sleep_for( std::chrono::seconds( N ) );
    std::cout << "pause of " << N << " second ended\n";
}

int main( ){

    std::thread threads[ 5 ];

    std::cout << "spawning 5 threads...\n";
    for( short index = 0; index < 5; ++index ){
        threads[ index ] = std::thread( pause_thread, index + 1 );  // move-assign thread
    }

    std::cout << "Down spawning threads, now waiting for them to join...\n";
    for( short index = 0; index < 5; ++index ){
        threads[ index ].join();
    }

    std::cout << "\nall threads joined\n";
}

/* output

spawning 5 threads...
Down spawning threads, now waiting for them to join...
pause of 1 second ended
pause of 2 second ended
pause of 3 second ended
pause of 4 second ended
pause of 5 second ended

all threads joined



*/
