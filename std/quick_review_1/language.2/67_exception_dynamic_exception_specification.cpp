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
/// 3. exception
//  dynamic exception specification
//
//  void f() throw( int );          okay,   function declaration
//  void f( *pf )() throw ( int );  okay,   pointer to function declaration
//  void f( void pf() throw( int) );    okay, pointer to function parameter declaration

// typedef int ( *pf )() throw( int );  // error,   typedef declaration

/******************/
#include <iostream>
/******************/

void one() throw( int ){
    puts( "I throws 'int' exception" );
    throw 12;
}

void two() throw( const char* ){
    puts( "I throws 'cosnt char*' exception" );
    throw "this is two";
}

int main(){

    try {
        one();
    } catch( int i ){
        puts( "function one that threw int exception was caught" );
        std::cout << i << '\n';
    }

    try {
        two();
    } catch ( const char* cch ){
        puts( "function two that threw 'const char*' exception was caught" );
        std::cout << cch << '\n';
    }



}

/* output:

I throws 'int' exception
function one that threw int exception was caught
12
I throws 'cosnt char*' exception
function two that threw 'const char*' exception was caught
this is two

*/
