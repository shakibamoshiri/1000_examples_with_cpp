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
/// initialization

#include <iostream>
#include <string>


// #include <iomanip>




int main(){

    // storage class specifier - static

    // each time the auto variable is initialized
    for( int i = 0; i < 10; ++i ){
        int stuff = 1;
        ++stuff;
        std::cout << stuff << ' ';      // 2 2 2 2 2 2 2 2 2 2
    }

    puts("");

    // but the static variable not!
    for( int i = 0 ; i < 10; ++i ){
        static int stuff = 1;
        ++stuff;
        std::cout << stuff << ' ';      // 2 3 4 5 6 7 8 9 10 11
    }


}



/* output:


*/
