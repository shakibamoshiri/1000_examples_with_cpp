/*

A review of abstraction section from cplusplus.com

*/

/// iomanip
//  setfill
//  /* unspecified */ setfill( char_type c )
//
//  Sets fill character.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <iomanip>  // input/output manipulators



int main(){

    std::cout << std::setfill( '-' ) << std::setw( 10 );
    std::cout << "you" << '\n';

}
/**
-------you

Process returned 0 (0x0)   execution time : 0.007 s
Press ENTER to continue.



**/
