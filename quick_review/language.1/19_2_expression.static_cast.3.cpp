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
    // static_cast< new_type >( input )
    // get input and return as a new_type
    // Converts between types using a combination of implicit and user-defined conversions.

    int i = 10;
    void* vptr = &i;

    int* iptr = static_cast<int*>(vptr);
    std::cout << *iptr << std::endl; // 10
}
