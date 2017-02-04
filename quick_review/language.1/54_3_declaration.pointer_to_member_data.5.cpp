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
    int data;
    int S::* p2d;
};

int main(){
    // pointer to data member


    S s { 3, &S::data };    // initials data and p2d

    int S::* in_main_ptr_2_date = &S::data;
    int S::* S::* in_main_ptr_2_p2d = &S::p2d;  // like int** p = p*

    // prints wtih s
    std::cout << s.data << ' ' << s.*(s.p2d) << '\n';   // okay 3   3

    s.data = 4;
    // prints with in_main ...
    std::cout << s.*in_main_ptr_2_date << ' ' << s.*(s.*in_main_ptr_2_p2d) << '\n'; // okay 4   4




}
/* output:


*/
