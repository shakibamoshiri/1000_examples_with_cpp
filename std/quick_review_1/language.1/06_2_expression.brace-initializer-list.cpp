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
    struct { int n; std::string name; } person;

    person = { 30, "Shakib" }; // brace-initializer-list

    std::cout << person.n << ' ' << person.name << std::endl;
}
