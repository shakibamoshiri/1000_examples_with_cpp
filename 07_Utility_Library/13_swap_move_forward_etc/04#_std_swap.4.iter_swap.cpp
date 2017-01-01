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

    int array_1[3] = {1, 3, 5};
    int array_2[3] = {0, 2, 4};

    int* const ptr_1 = array_1;
    int* const ptr_2 = array_2;

    std::cout << *ptr_1 << ' ' << *ptr_2 << '\n';       // 1 0

    std::iter_swap( ptr_1, ptr_2 );
    std::cout << *ptr_1 << ' ' << *ptr_2 << '\n';       // 0 1

}
