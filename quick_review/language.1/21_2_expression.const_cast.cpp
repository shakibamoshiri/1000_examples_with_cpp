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

    // const_cast< new_type > ( expression )
    // Returns a value of new_type

    short one = 20;                     // first, initializes the variable
    const short& ref2one = one;         // seconds, makes a const reference from it
    const_cast<short&>(ref2one) = 3;    // third, modifies by using const_cast
    std::cout << one << std::endl;      // okay

    //
    const short two = 200;
    short* ptr2two = const_cast<short*>(ptr2two);
    *ptr2two = 2;                       // undefined behavior
    std::cout << two << std::endl;

    // NOTE:
    // const_cast does not work on function pointer
}
