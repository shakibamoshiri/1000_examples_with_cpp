/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
//
//  template< class CharT >
//  /* unspecified */ put_time( const struct tm* tmb, const char* fmt );
//
//  Puts date and time.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators
#include <chrono>
#include <ctime>


int main(){

    using std::chrono::system_clock;

    std::time_t tt = system_clock::to_time_t( system_clock::now() );

    std::tm* ptm = std::localtime( &tt );
    std::cout << "now (local time): " << std::put_time( ptm, "%c" ) << '\n';

}
/**

now (local time): Tue Mar 14 17:30:32 2017

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.


**/
