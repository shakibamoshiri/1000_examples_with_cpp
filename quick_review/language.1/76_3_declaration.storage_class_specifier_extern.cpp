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
#include "extern.cpp"

extern const int function(int); // like below

extern int global;      // it declared in extern.cpp, see extern.cpp
                        // int global = 10;



int main(){

    // storage class specifier - extern

    std::cout << global << '\n';        // print 10

    std::cout << function( 1 ) << '\n';     // print 1

    std::cout << function( global ) << '\n';    // print 10

}



/* output:


*/
