/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
//  get_time
//  template <class charT>
//  /*unspecified*/ get_time (struct tm* tmb, const charT* fmt);

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators
#include <string>


int main(){

    std::tm when;
    std::cout << "enter the time: ";
    std::cin >> std::get_time( &when, "%R" );   // extract time (24H format)

    if( std::cin.fail() ) std::cout << "error: reading time\n";
    else std::cout << "the entered time is: " << when.tm_hour << " hours and " << when.tm_min << "minutes\n";

}
/**
enter the time: 22:33
the entered time is: 22 hours and 33minutes

Process returned 0 (0x0)   execution time : 2.831 s
Press ENTER to continue.



**/
