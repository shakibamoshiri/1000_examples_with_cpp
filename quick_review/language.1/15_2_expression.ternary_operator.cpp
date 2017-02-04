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

int main(){
    // ternary operator

    // simple r-value
    int n = 1 > 2 ? 10 : 12; // n becomes 12
    std::cout << n << '\n';

    // simple l-value
    int m = 11;
    (n == m ? n : m) = 1000;    // n not equal to m so m is assigned with 1000
    std::cout << m << std::endl;

    std::string string = (2 + 2 == 4) ? "This is a string" : throw std::logic_error("2 + 2 != 4");
    std::cout << string << std::endl; // This is a string
}
