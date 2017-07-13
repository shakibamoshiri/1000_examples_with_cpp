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



    S s { 3, &S::data };

    std::cout << s.data << ' ' << s.*(s.p2d) << '\n';   // okay: 3 3

    s.data = 4;
    std::cout << s.data << ' ' << s.*(s.p2d) << '\n';   // okay: 4 4


}
/* output:


*/
