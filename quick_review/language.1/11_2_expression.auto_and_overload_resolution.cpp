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

void f (int){}  // overload
void f (char){} // overload


int main(){

    void (*fptr)(int) = f;  // okay overload resolution

    // auto afptr = f; // error
    auto afptr = static_cast<void (*)(char)>(f); // okay overload resolution duo to cast
}
