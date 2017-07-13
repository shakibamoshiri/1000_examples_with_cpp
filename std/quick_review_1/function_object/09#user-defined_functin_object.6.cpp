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

// To solve the problem with initialize a function object with more than
// one argument we can use parameter-pack expression, a great feature in c++

template< class Return, class... Argument > struct create_function {};

template< class Return, class... Argument >
struct create_function< Return( Argument... ) > {
    // first typedef
    typedef Return( *Fo_t )( Argument... ); // okay

    // create new object of it
    Fo_t user_apply_function;

    // declare default constructor
    // for initializing the object to nullptr
    create_function( ) : user_apply_function( nullptr ) {}

    // second constructor for initializing the user function
    create_function( Fo_t temp_func ) : user_apply_function( temp_func ) {}

    // define the operator()
    Return operator()( Argument... args ){
        puts( ">>> operator() was called <<<" );
        return user_apply_function( args... );
    }
};

// NOTE, all three functions have the same name!

void func ()         // with no argument
{ puts( "void() with no argument" ); }

void func ( int )    // with one
{ puts( "void( int ) with one argument" ); }

int func( int one, int two ) // with two arguments and return the sum of them
{ return one + two; }

int main(){

    create_function< void() > no_arg = func;
    no_arg();

    create_function< void( int ) > one_arg;
    one_arg = func;
    one_arg( 1 );

    create_function< int( int, int ) > two_arg;
    two_arg = func;
    int sum = two_arg( 1, 2 );
    std::cout << sum << '\n';


}


/* output:

>>> operator() was called <<<
void() with no argument
>>> operator() was called <<<
void( int ) with one argument
>>> operator() was called <<<
3

*/
