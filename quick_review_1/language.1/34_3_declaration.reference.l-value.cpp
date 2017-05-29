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


int main(){

    // l-value reference

    int number = 3;     // number is a l-value
                        // and also r-value for other l-value
                        // like below:

    int* ptr2number = &number;  // ptr2number is a l-value
                                // and it cab be r-value for other l-value
                                // like below:

    int& ref2ptr = *ptr2number; // okay l-value reference to a r-value pointer and below
    int& ref2number = number;   // okay l-value reference to a r-value value


}
