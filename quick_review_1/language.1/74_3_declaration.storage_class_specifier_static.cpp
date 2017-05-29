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


void function(){

    static int static_int = 0;
    ++static_int;
    printf( "static_int is: %d\n", static_int );
}

int main(){

    // storage class specifier - static


    // It looks like a global variable but belongs to function scope
    function(); // 1
    function(); // 2
    function(); // 3
    function(); // 4

}



/* output:


*/
