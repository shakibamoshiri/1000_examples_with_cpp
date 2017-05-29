/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>




int main(){

    const char* hw = "how are you today?";

    std::istringstream iss(hw);

    char store[5]{};
    iss >> store;
    std::cout << store << std::endl;

    iss.seekg(0);   // rewind
    iss >> store;
    std::cout << store << std::endl;

}
