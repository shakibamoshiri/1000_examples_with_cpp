/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <iterator>

// empty

int main(){
    typedef std::basic_string<char> string;

    string str = "hard work pays off";

    std::boolalpha( std::cout );

    std::cout << str.empty() << std::endl; // false
    std::cout << str.capacity() << std::endl; // 18

    str.clear(); // remove all character form the str

    std::cout << str.empty() << std::endl; // true
    std::cout << str.capacity() << std::endl; // 18
}




