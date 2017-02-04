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
    // comma-operator

    int value = 10;

    std::cout << (value++,      // after it become 11
                  ++value,      // 11 + 1 = 12
                  (value/=2),   // 12 / 2 = 6
                  value)        // the output is 6
              << std::endl;


    // another example
    std::cout << (value*=2,--value,value--,value) << std::endl; // 10
}
