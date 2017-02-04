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

constexpr unsigned long long operator"" _length(const char* value, std::size_t N){ return N; }

int main(){

    // okay and valid
    int number = "abcdefghijklmnopqrstuvwxyz"_length;
    std::cout << number;    // 26

    // error and not valid
    const char* name = "k-five";
//    int size_name = *name_lenght;

}
