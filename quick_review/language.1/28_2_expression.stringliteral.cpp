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
#include <string>

constexpr unsigned long long operator"" pow(unsigned long long value){ return (value * value); }

int main(){

    int number = 2pow;
    std::cout << number << std::endl;

    number = 9pow;
    std::cout << number << std::endl;

}
