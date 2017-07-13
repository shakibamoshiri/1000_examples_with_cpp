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
    static void print( int temp ){ std::cout << temp << '\n'; }
};

int main(){
    // pointer to member function

    // error
    // void (S::* fptr_2_S)(int) = &S::print;

    // correct
    void (* fptr_2_S)(int) = &S::print;

    // okay
    S::print(3); // okay    3

    S one;
    one.print(1);   // okay 1

    fptr_2_S(4);    // okay 4   like a regular function outside a struct or class (global function)
}
/* output:


*/
