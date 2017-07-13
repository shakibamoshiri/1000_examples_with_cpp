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

void print_1( int i ){
    std::cout << "void print( int ) with: "
              << i << '\n';
}

void print_2( int i, float f ){
    std::cout << "void print( int, float ) with: "
              << i << ' ' << f << '\n';
}


int main(){

    // std::bind

    std::function< void( int ) > first = std::bind( print_1, 1 );
    first( 2 );

    std::function< void( int, float ) > second = std::bind( print_2, 1, 1.1 );
    second( 2, 2.2 );

    // the output has the value of the std::bind!

}



/* output:

void print( int ) with: 1
void print( int, float ) with: 1 1.1

*/
