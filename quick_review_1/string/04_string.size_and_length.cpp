/*
        quick review string library
        ***************************

*/

#include <iostream>
#include <string>
#include <iterator>

// size or length

int main(){
    typedef std::basic_string<char> string;

    string str = "test size and length";

    string::size_type sz = str.size();
    std::cout << sz << std::endl;       // 20

    sz += str.capacity();
    sz += std::distance(str.begin(), str.end());

    // sz == 60

    std::cout << ( sz == 60 ? "okay" : "not" ) << std::endl; // okay ==
}




