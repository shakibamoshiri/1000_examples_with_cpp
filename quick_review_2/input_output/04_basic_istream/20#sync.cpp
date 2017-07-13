/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::sync
//  int sync();
//
//  Synchronize input buffer


#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <cctype>   // std::isdigit



int main(){

    char first, second;
    std::cout << "please enter a word: ";
    first = std::cin.get();
    std::cin.sync();

    std::cout << "Please enter another word: ";
    second = std::cin.get();

    std::cout << "the first word began by: " << first << '\n';
    std::cout << "the second word began by: " << second << '\n';
}
/**



**/
