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
/// function

#include <iostream>
#include <tuple>
#include <utility>  // pair


// auto f1(){ return { 1, 2, 3 }; }        // error

std::pair< int, int > f2(){ return { 1, 2 }; }  // okay

std::tuple< int, int, int > f3(){ return { 1, 2, 3 }; } // okay since c++17


int main(){


}
/* output:


*/
