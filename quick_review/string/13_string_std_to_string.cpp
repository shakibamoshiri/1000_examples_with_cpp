/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <sstream>

// std::to_string

int main(){
    typedef std::basic_string<char> string;

    string str = std::to_string(3.43);
    std::cout << str << std::endl;

    str =  std::to_string(3311);
    std::cout << str << std::endl;
}




