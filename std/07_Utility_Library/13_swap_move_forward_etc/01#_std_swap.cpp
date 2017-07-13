/*
        swap
        forward
        move
        type operation
        hash
        and so on.
        **********



*/
/// std::swap
//
//  defined in header <algorithm>
//  defined in header <utility>
//
//  Exchanges the given values ( also an array ).

#include <iostream>
#include <algorithm>

int main(){

    int one = 1, two = 2;

    std::swap( one, two );

    std::cout << two;   // 1

}
