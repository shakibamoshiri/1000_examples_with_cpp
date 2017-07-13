/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>

// front

int main(){
    typedef std::basic_string<char> string;

    string str ("how are you today?");

    str.front(); // h
    const char& rstr = str.front();

    std::cout << rstr; // h
    std::cout << &rstr; // how are you today?

    std::cout << str.front() << std::endl;
    std::cout << &str.front() << std::endl;
}




