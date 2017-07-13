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

    for (std::string line; std::cout << "Enter anything: " && getline(std::cin, line) && line != "exit";std::cout << "\nYou entered: " << line << '\n');

}
