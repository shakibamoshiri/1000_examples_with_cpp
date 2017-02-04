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

int function () { return 33; }

int main(){
    // reinterpret_cast < new_type > ( expression )
    // Converts between types by interpreting the underlying bit pattern
    // May it does not complier to any CPU instructions.

    int (*fptr)() = function;
    std::cout << fptr() << std::endl;   // 33

//    void (*fptr_void)() = function;     // error: invalid conversion form int (*)() to void (*)()
    void (*fptr_void)() = reinterpret_cast<void(*)()>( function );    // okay but!
//    fptr_void();                        // undefined behavior

    // okay
    int (*fptr_again)() = reinterpret_cast<int(*)()>( fptr_void );
    std::cout << fptr_again() << std::endl;     // 33

}
