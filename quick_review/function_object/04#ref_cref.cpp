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

void print_1( int& i ){
    ++i;    // okay with std::ref
    std::cout << "void print( int ) with: "
              << i << '\n';
}

void print_2( int& i2, float f ){
    ++i2; // error with std::cref
    std::cout << "void print( int, float ) with: "
              << i2 << ' ' << f << '\n';
}


int main(){

    // std::bind
    int i = 1;
    int i2 = 2;
    std::function< void( int ) > first = std::bind( print_1, std::ref( i ) );
    first( 0 );

    // with std::ref:   okay
    // with std::cref:  error
    std::function< void( int, float ) > second = std::bind( print_2, std::cref( i2 ), 1.1 );
    second( 0, 0.0 );

    std::cout << "at the end: " << i << ' ' << i2 << '\n';

}


/* output:



*/
