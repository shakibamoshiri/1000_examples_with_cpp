/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::gcount
//  streamsize gcount() const
//
//  Gets characters count

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf




int main(){

    char c_string[ 30 ]{};

    std::cout << "Please enter a simple string: ";
    std::cin.getline( c_string, 30 );
    std::cout << c_string << '\n';
    std::cout << std::cin.gcount() << '\n';

}
/**

Please enter a simple string: one two
one two
8

Process returned 0 (0x0)   execution time : 6.169 s
Press ENTER to continue.


**/
