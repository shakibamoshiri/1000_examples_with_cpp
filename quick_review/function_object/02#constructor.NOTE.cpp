/*
    quick review:
    General-Purpose Utility

    01. program utility
    02. date and time
    03. function object
    04. bitset
    05. pair
    06. tuple
    07. swap, forward, move
    08. type operations
    09. hash support

*/
/// 03. function object in header <functional>


#include <iostream>
#include <functional>

void print( int ){
    std::cout << "void print( int )\n";
}

void print( int, float ){
    std::cout << "void print( int, float )\n";
}


int main(){

    // the function-object can not handle the overloaded functions
    // error
    std::function< void( int ) > first = print;
    first( 1 );
    // also has error
    std::function< void( int, float ) > second = print;
    second( 1, 1.1 );

}



/* output:



*/
