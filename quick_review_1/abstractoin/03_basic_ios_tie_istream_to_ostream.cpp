/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::ofstream ofs("03.txt");
    std::ifstream ifs("03.txt");

    std::string value("empty");

    ofs << "hello world\n";
    ifs >> value;

    std::cout << "Before using tie:\t" << value << std::endl;

    ifs.clear();
    ifs.tie(&ofs); // ties out and in together

    ifs >> value;

    std::cout << "After using tie:\t" << value << std::endl;

    ofs << "for the second times adding to 'ofs'\n";
    ifs >> value;   // in the buffer 'world' is exist so first we have 'world'
    std::cout << value << std::endl;
    ifs >> value;   // then 'for'
    std::cout << value << std::endl;
    ifs >> value;   // then 'the'
    std::cout << value << std::endl;

    while( ifs >> value ) std::cout << value << ' ';



}
