/*
        std::tuple
        **********

defined in header <tuple>


NOTE:
Until C++17, a function could not return a tuple using list-initialization:

std::tuple<int, int> f (){
    return {1, 3};                  // error until c++17
    return std::make_tuple( 1, 3 ); // always works
}
*/


#include <iostream>
#include <tuple>

// note this function did not work before c++17
// but right now it works for std::pair

std::pair< int, int > f(){
    return {1, 2};
}

int main( ){

    int one, two;

    std::tie( one, two ) = f();

    std::cout << one << ' ' << two; // 1 2

}
