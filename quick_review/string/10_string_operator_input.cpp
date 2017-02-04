/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <sstream>

// operator >> and <<

int main(){
    typedef std::basic_string<char> string;

    string str = "hard work pays off";

    typedef std::basic_istringstream<char> iss;

    iss istr(str); // now buffer contains str.data

    string str2;

    istr >> str2;
    std::cout << str2 << std::endl; // hard

    istr >> str2;
    std::cout << str2 << std::endl; // hard
}




