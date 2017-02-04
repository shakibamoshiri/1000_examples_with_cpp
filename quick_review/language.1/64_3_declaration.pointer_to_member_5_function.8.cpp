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
#include <functional>

// #include <iomanip>





int main(){

    std::string::size_type  (std::string::* fptr)() const noexcept = &std::string::size;

    std::string she( "how are you today?" );

    std::cout << she.size() << '\n';            // okay prints 18

    std::cout << (she.*fptr)() << '\n';           // okay prints 18

}



/* output:


*/
