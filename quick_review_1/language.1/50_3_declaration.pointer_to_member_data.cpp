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
    int data = 1;
    static int data_2;
};

int S::data_2;  // without this definition it will, undefined reference in std::cout

int main(){
    // pointer to data member

    int S::* p2data = &S::data; // or &(S::data);

    std::cout << p2data << '\n';    // 1

    // error:
    // S::data = 2;
    S s;
    s.*p2data = 3;  // not through data, but thought p2data
    std::cout << s.data << '\n';    // 3

    // but with static is okay
    S::data_2 = 2;
    int * static_p2data = &S::data_2;

    std::cout << *static_p2data << '\n';    // 2



}
/* output:


*/
