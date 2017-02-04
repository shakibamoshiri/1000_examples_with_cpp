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

    /// r-value
    // R-value reference can be used to extended lifetime of temporary object.
    // Note:
    // A l-value reference to const can extended the lifetime of temporary object, too
    // but they are not modifiable through them.

                                // r-value only binds to r-value
    int number = 3;             // 3 is a r-value and number is a l-value

//    int&& r_value = number;     // error, cannot bind to a l-value
                                // and compiler says: error: cannot bind ‘int’ lvalue to ‘int&&’

    int&& r_value = 3;          // okay
    r_value += 3;               // okay, it is modifiable
    std::cout << r_value
              << '\n';          // 6



}
