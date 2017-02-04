/*
        overview
    abstraction textbook

*/

#include <iostream>
#include <fstream>




int main(){

    // overload << for ostream

    std::ofstream ("11.txt") << "test the r-value overload for ofstream\n";

    std::string test;
    std::ifstream ("11.txt") >> test;   // okay but only first word

    std::cout << test << std::endl;     // outputs: test
}
