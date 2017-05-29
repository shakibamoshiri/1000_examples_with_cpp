/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// expression

#include <iostream>


int main(){

    int array[] = {2, 4, 6, 8, 10, 12, 14, 16};
    // index is    0, 1, 2, 3, 4,  5 ,  6, 7

    int* ptr = &array[3];
    // index for pointer ptr:
    //            {-3,-2,-1,0, 1, 2,   3,  4 }

    // here is the other example
    std::cout << (-3)[ptr] << ' '       // 2
              << (-2)[ptr] << ' '       // 4
              << (-1)[ptr] << ' '       // 6
              <<    0[ptr] << ' '       // 8
              <<    1[ptr] << ' '       // 9
              <<    2[ptr] << ' '       // 10
              <<    3[ptr] << std::endl;// 12



}
