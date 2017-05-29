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

    int* ptr = &array[2];

    std::cout << ptr[1] << ' '      // 8 why? =>        ptr == 6, so ptr[1] means 8
              << ptr[-1] << ' '     // 4 why? =>        ptr == 6, so ptr[-1] become 4
              << 1[ptr] << ' '      // 8 why? =>        see the next example in the next file :)
              << (-1)[ptr]          // 4 also same as above :)
              << std::endl;


}
