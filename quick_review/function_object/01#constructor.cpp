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

void print_2( int, float ){
    std::cout << "void print( int, float )\n";
}


int main(){

    std::function< void( int ) > first = print;
    first( 1 );

    std::function< void( int, float ) > second = print_2;
    second( 1, 1.1 );

}



/* output:

void print( int )
void print( int, float )

*/
