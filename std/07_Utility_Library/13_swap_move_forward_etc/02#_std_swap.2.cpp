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

    std::swap( array_1, array_2 );

    for( const int temp : array_2 ) std::cout << temp << ' ';   // 1, 3, 5

}
