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
    const int data_read_only = 1;
};

int main(){
    // pointer to data member

    int S::* p2d = &S::data;
    const int S::* p2dro = &S::data_read_only;

    S s = { 2 };
    std::cout << s.data << ' ' << s.data_read_only << '\n'; // 2 1

    std::cout << s.*p2d << ' ' << s.*p2dro << '\n';         // 2 1

}
/* output:


*/
