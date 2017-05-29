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

//  may you would like to define a function object to yourself

#include <iostream>
#include <functional>

template< typename Return, typename Argument = void >
struct fobj {};

template< typename Return, typename Argument >
struct fobj< Return ( Argument ) > {

    typedef Return ( *Fo_t )( Argument );   // Fo_t is a type
};

void print( int ){
    std::cout << "void print( int )\n";
}

int main(){

    // here we have use typedef call, to initialize the object
    // by using ::Fo_t ...
    // but with using it, was can also create an object
    // follow the next examples
    fobj< void( int ) >::Fo_t first = print;
    first( 1 );

}


/* output:



*/
