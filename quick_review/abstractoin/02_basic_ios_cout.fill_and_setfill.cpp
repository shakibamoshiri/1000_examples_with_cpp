/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <iomanip>

int main(){

    std::cout << "Hello" << std::endl;
    std::cout.fill('_');
    std::cout << std::cout.fill() << std::setw(10) << "\n";

    std::cout << "world" << std::endl;
    std::cout << std::setfill('*') << std::setw(10) << "\n";

}
