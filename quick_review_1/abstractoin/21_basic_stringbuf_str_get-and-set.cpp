/*
        overview
    abstraction textbook

*/

#include <iostream>
//#include <sstream>
#include <sstream>



int main(){

    std::istringstream input;

    input.rdbuf()->str("a b c");            // set through str()
    std::cout << input.str() << std::endl; // get from str()

}
