/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>


// substr

int main(){
    typedef std::basic_string<char> string;

    string str = "hard work pays off";

    std::cout << str.substr(5) << std::endl; // work pays off

    std::cout << str.substr(10) << std::endl; // pays off

    std::cout << str.substr(0, 5) << std::endl; // work
}




