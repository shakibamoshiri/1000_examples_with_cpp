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

    int number = 3;

    // compiler gave error for static_cast:
    // error: invalid static_cast from type ‘int*’ to type ‘uint64_t* {aka long long unsigned int*}’
    // uint64_t* uptr64 = static_cast<uint64_t*>(&number);

    // okay with reinterpret_cast
    uint64_t* uptr64 = reinterpret_cast<uint64_t*>(&number);
    *uptr64 = 33;
    std::printf("number is %d\n", number);  // okay and the output is 33

}
