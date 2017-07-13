/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <iterator>

// shrink_to_fit

int main(){
    typedef std::basic_string<char> string;

    string str;

    std::cout << str.capacity() << std::endl; // output is 0

    str.resize(30);

    std::cout << str.capacity() << std::endl; // now output is ? 30

    str.clear(); // not str has not data

    std::cout << str.data() << std::endl; // nothing

    std::cout << str.capacity() << std::endl; // it still is 30

    str.shrink_to_fit(); // now capacity is 0

    std::cout << str.capacity() << std::endl;

    // for me by default take 15 but for you may 0 or more
}




