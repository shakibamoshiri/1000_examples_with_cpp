/*
        overview
    abstraction textbook

*/

#include <iostream>
//#include <sstream>
#include <sstream>



int main(){

    std::istringstream input("      how    are   you   today?           ");

    std::string line;
    std::getline(input, line);
    std::cout << line << std::endl;

    line="";
    input.seekg(0);
    getline(input >> std::ws, line); // std::ws : discards leading whitespace from an input stream. only from the beginning of the file
    std::cout << line << std::endl;
}
