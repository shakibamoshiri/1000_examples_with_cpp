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
    int get_data( int temp ){ return temp; }
};

int main(){
    // pointer to member function

    int (S::* fptr_2_S)(int) = &S::get_data;

    S object;

    std::cout << object.get_data(1) << '\n';    // okay returns 1

    std::cout << (object.*fptr_2_S)(2) << '\n'; // okay returns 2
}
/* output:


*/
