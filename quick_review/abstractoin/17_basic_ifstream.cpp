/*
        overview
    abstraction textbook

*/

#include <iostream>
//#include <sstream>
#include <fstream>



int main(){
    std::ifstream ifs1("16.out1");
    std::ifstream ifs2( std::move(ifs1) );

    std::cout << ifs2.rdbuf() << std::endl; // context of ifs1
    std::cout << ifs1.rdbuf() << std::endl; // nothing


}
