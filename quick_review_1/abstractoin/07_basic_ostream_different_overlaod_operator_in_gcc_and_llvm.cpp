/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <sstream>


int main(){

    std::cout << (std::ostringstream("how are you today?")).str() << std::endl; // okay

//    std::cout << (std::ostringstream() << "how are you today?").str() << std::endl; // error in gcc but okay in LLVM

}
