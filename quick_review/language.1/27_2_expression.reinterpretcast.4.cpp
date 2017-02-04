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
    // reinterpret_cast < new_type > ( expression )
    // Converts between types by interpreting the underlying bit pattern
    // May it does not complier to any CPU instructions.

    int number = 65;

    char* ch_ptr = (char*) &number;
    std::cout << *ch_ptr << std::endl;      // A

    char* ch_ptr_2 = reinterpret_cast<char*>( &number );
    std::cout << *ch_ptr_2 << std::endl;    // A

}
