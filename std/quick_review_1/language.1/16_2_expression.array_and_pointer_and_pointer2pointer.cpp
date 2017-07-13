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
    // array and pointer

    char** ptr = 0;     // okay | two level pointer
    char** ptr2 = ptr;  // okay | the two level are equal

    /// const char** cptr = ptr; // error not equal cv-qualify in the same level
    const char* const* cptr = ptr;  // okay each level has const-volatile qualify

    int array [2][3];
    /// int** ptr2array = array; // error
    int (*ptr2array)[3] = array;    // okay
}
