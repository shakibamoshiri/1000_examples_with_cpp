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

    int array[] = {2, 4, 6, 8};

    int* ptr = array;

    // here is the answer:
    std::cout << 0[ptr] << ' '
              << 1[ptr] << ' '
              << 2[ptr] << ' '
              << 3[ptr] << std::endl;
              // I do not know how it possible but I know it works fine
              // and see the next example in the next file


}
