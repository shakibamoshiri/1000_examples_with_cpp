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

template< class Re, class Arg = Re> struct fobj {};   // primary-declaration

template< class Re, class Arg >
struct fobj< Re( Arg ) > {
    // first typedef:
    typedef Re ( *Fo_t )( Arg );    // okay not we have the type Fo_t

    // create a new object
    // instead of this:
    // Fo_t user_function = nullptr;
    // we can declare the default constructor and initialize the object to nullptr
    Fo_t user_function;

    // declare constructor
    fobj( ) : user_function( nullptr ) {};
    fobj( Fo_t temp_func ) : user_function( temp_func ) {};

    Re operator()( Arg arg ){
        return user_function( arg );
    }

};

void print( int i ){
    std::cout << "void print( int ) with value: " << i << '\n';
}

int what( int i ){
    std::cout << "int what( int ) that returns: " << i << '\n';
    return i;
}

int main(){

    fobj< void( int ) > first;  // called default constructor with nullptr initialization
    first = print;
    first( 3 ); // void print( int ) with value: 3

    fobj< int( int ) > second;  // called default constructor with nullptr initialization
    second = what;
    int r = second( 1 );    //  int what( int ) that returns: 1
    std::cout << r << '\n'; //  1

}


/* output:



*/
