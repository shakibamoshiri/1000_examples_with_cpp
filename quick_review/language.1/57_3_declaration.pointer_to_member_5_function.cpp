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
// #include <string>
// #include <iomanip>

struct S {
    void print( int temp ){ std::cout << temp << '\n'; }
};

int main(){
    // pointer to member function

    void (S::* fptr_2_S)(int) = &S::print;

    // error
    // S::print(3); // cannot call member function without object

    S one;
    one.print(1);   // okay 1

    (one.*fptr_2_S)(2); // okay 2

    // Error it need be surrounded by () parentheses
//    one.*fptr_2_S(3);




}
/* output:


*/
