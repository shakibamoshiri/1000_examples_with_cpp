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

    // error
//    typedef std::string::size_type ( std::string::* fptr_string_t )() const noexcept;

    // okay
    typedef std::string::size_type ( std::string::* fptr_string_t )() const;

    // okay
    fptr_string_t p2size = &std::string::size;





}



/* output:


*/
