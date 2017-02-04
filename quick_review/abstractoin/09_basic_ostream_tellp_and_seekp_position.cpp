/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>


int main(){

    // tell position
    std::ostringstream oss;
    std::cout << oss.tellp() << std::endl;

    oss << 'h';
    std::cout << oss.tellp() << std::endl;

    oss << "ow are you";
    std::cout << oss.tellp() << std::endl;

    oss << " today?\n";
    std::cout << oss.tellp() << std::endl;
    std::cout << oss.str() << std::endl;

    // seek position
    oss.seekp(17);
    oss << '!';
    oss.seekp(0);
    oss << 'H';

//     std::cout << oss.seekp() << std::endl; cannot print it
    std::cout << oss.tellp() << std::endl;
    std::cout << oss.str() << std::endl;



}
