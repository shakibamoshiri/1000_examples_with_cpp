/*
        quick review containers library
        *******************************

*/

#include <iostream>
#include <array>

// constructor

int main(){

    // construction uses aggregate initialization
    std::array<int, 5> one { {1,2,3,4,5} };         // in c++11

    std::array<int, 5> two {1,2,3,4,5};             // in c++14, does not require

    std::array<char,5> three {'a','b','c','e','f'};

    std::array<std::string, 2> four { std::string("str 1"), "str 2" };





}




