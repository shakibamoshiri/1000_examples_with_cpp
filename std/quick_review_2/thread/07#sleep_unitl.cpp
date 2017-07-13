/*

A review of thread library

*/
/// std::this_thread::sleep_until

#include <iostream>
#include <atomic>
#include <thread>
#include <iomanip>
#include <ctime>



int main( ){

    using namespace std::chrono;
    std::time_t tt = std::time( 0 );

    std::tm* ptm = std::localtime( &tt );

    std::cout << "current time: " << std::put_time( ptm, "%X" );

    std::cout << " waiting for the next minute to begin...\n";
    ++ptm->tm_min;
    ptm->tm_sec = 0;
    std::time_t until = std::mktime( ptm );
    std::this_thread::sleep_until( system_clock::from_time_t( mktime( ptm ) ) );
//    std::cout << until << '\n';
//    std::cout << system_clock::from_time_t( mktime( ptm ) ) << '\n';
    std::cout << "now the time is: " << std::put_time( ptm, "%X" );

}

/* output

current time: 17:36:40 waiting for the next minute to begin...
now the time is: 17:37:00


*/
