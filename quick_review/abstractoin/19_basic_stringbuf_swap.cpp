/*
        overview
    abstraction textbook

*/

#include <iostream>
//#include <sstream>
#include <sstream>



int main(){

    std::istringstream input("one two three");
    std::ostringstream output;

    *output.rdbuf() = std::move( *input.rdbuf());
    std::cout << output.rdbuf() << std::endl;
    std::cout << input.rdbuf() << std::endl;


}
