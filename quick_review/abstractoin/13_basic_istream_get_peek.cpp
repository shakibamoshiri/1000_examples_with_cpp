/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>




int main(){
    std::istringstream iss("how are you today?");

    // peek: read but not extract
    // get:  read and extract
    std::cout << (char)iss.peek() << std::endl;     // h
    std::cout << iss.tellg() << std::endl;          // 0

    std::cout << std::endl;

    std::cout << (char)iss.get() << std::endl;      // h
    std::cout << iss.tellg() << std::endl;          // 1

    char stuff[11]{};

    iss.get(stuff,11);
    std::cout << stuff << std::endl;
    std::cout << iss.tellg() << std::endl;

}
