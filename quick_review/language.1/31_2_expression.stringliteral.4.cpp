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

constexpr long operator"" size(const char* str, std::size_t N){ return N; }

int main(){

    // okay and valid
    int size_of_name[] = {"one"size, "two"size, "three"size, "four"size, "five"size };

    for( int tmp : size_of_name ) std::cout << tmp << ' ';
    // the output is: 3 3 5 4 4

}
