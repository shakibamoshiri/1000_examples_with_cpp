/*
            language 2
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. Classes
2. Templates
3. Exceptions
4. Statements
5. Miscellaneous

*/
/// 2. template
//  partial template specialization


/******************/
#include <iostream>
#include <functional>
#include <vector>
#include <list>
/******************/

// primary template
template< typename Return, typename Argument = Return >
struct S {};

// template specialization for: type ( )
template< typename Return >
struct S < Return ( ) > {
    typedef Return ( *Func ) ();

    Func f_obj;

    S( Func temp ) : f_obj ( temp ) {}

    void operator()(){
        f_obj();
    }
};

// template specialization for: type( type )
template< typename Return, typename Argument >
struct S < Return ( Argument ) > {
    typedef Return ( *Func ) ( Argument );

    Func f_obj;

    S( Func temp ) : f_obj ( temp ) {}

    Return operator()( Argument value ){
        return f_obj( value );
    }

};



void print( int value ){ std::cout << "value: " << value << '\n'; }

void print( void  ){ std::cout << "print" << '\n'; }

float print( float value ){ return value; }

void print( const char* cstring ){ std::cout << "cstring == " << cstring << '\n'; }

std::string print( const std::string cpp_string ){ return cpp_string; }

void print( std::vector< int > vector_of_int ){
    for( int temp : vector_of_int ) std::cout << temp << ' ';
}

int print( std::list< int > list_of_int ){

    unsigned int sum = 0;
    for( int temp : list_of_int ) sum += temp;

    return sum;
}



int main(){
    // why std::function does not wrap overloaded function while it is possible?
    //
    // I wanted to do more practice in **partial template specialization** and made
    // some function object just for making it sense to myself and It worked as
    // I expected
    //
    // But before doing this practice I had read the std::function object and for overloaded function
    // the compiler gave the error ( for example ):
    // error: conversion from ‘<unresolved overloaded function type>’ to non-scalar type ‘std::function<void()>’ requested
    // If we want to create an object from overloaded functions
    //
    // void print( int value ){}
    // char print( char value ){}
    //
    // std::function< void( int ) > f_obj = print;  error


    S< void( void ) > f_1 = print;
    f_1();

    S< void( int ) >  f_2 = print;
    f_2( 2 );

    S< float( float ) > f_3 = print;
    std::cout << "float == " << f_3( 3.3f ) << '\n';

    S< void( const char* ) > f_4 = print;
    f_4( "const char*\n" );

    S< std::string( std::string ) > f_5 = print;
    std::cout << f_5( std::string{ "cpp_string\n" } );

    std::vector< int > vector_of_int = { 1, 3, 5 };
    S< void( std::vector< int > ) > f_6 = print;
    f_6( vector_of_int );

    std::cout << '\n';
    std::list< int > list_of_int = { 2, 4, 6 };
    S< int( std::list< int > ) > f_7 = print;
    std::cout << f_7( list_of_int );



}

/* output:

print
value: 2
float == 3.3
cstring == const char*

cpp_string
1 3 5
12

*/
