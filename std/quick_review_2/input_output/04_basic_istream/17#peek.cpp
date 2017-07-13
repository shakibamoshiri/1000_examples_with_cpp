/*

A review of abstraction section from cplusplus.com

*/

/// basic_istream::peek
//  int_type peek()
//
//  Peeks the next character.

#include <iostream> // std::cout, std::ios, std::streamsize, std::streambuf
#include <fstream>
#include <cctype>   // std::isdigit



int main(){

    std::cout << "Please enter a number or a word: ";
    std::cout.flush();  // to unsure the output is written

    std::cin >> std::ws;    // eating up any leading whitespace
    std::istream::int_type c;
    c = std::cin.peek();    // peek character

    if( c == std::char_traits< char >::eof() ) return 1;
    if( std::isdigit( c ) ){
        int number;
        std::cin >> number;
        std::cout << "you entered the number: " << number << '\n';
    } else {
        std::string word;
        std::cin >> word;
        std::cout << "you entered the word: " << word << '\n';
    }

}
/**

Please enter a number or a word: k-five
you entered the word: k-five

Process returned 0 (0x0)   execution time : 3.972 s
Press ENTER to continue.**

Please enter a number or a word: 123
you entered the number: 123

Process returned 0 (0x0)   execution time : 2.240 s
Press ENTER to continue.

**/
