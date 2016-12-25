/*
        std::tuple
        **********

defined in header <tuple>

Class template std::tuple is a fixed-size collection of heterogeneous
values. It is a generalization on std::pair.

Template Parameter:
    Type...                     the type of elements that the tuple is stored. Empty list is supported.

Member Function:
    constructor                 constructs a new tuple
    operator =                  assigns the contents of one tuple to another
    swap                        swaps the contents of two tuples

*/

/// std::tuple constructor
//  Constructs a new tuple.

#include <iostream>
#include <tuple>

// note this function did not work before c++17
// but right now it works
// UTC:	Sun Dec 25 09:54:39 2016 GMT

std::pair< int, int > f(){
    return {1, 2};
}

int main( ){

    int one, two;

    std::tie( one, two ) = f();

    std::cout << one << ' ' << two; // 1 2

}
