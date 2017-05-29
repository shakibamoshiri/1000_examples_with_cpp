/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>


// compare

int main(){
    typedef std::basic_string<char> string;

    string str = "hard work pays off";

    !(str.data() == "hard work pays off") ? std::cout << "okay both equal\n" : std::cout << "not equal"; // output is okay

    if ( ! str.compare("hard work pays off") ) std::cout << "the same\n";
    else                                       std::cout << "not\n";
}




