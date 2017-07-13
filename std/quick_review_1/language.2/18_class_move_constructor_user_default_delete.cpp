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
/// class
//  move constructor
//


/******************/
#include <iostream>
#include <algorithm>

//
class A {
private:
    const char* name = "";

public:
    A( const char* temp ) : name( temp ){
        puts( "default constructor..." );
    }         // default constructor

    A( A&& other ) : name( std::move( other.name ) ){
        puts( "move constructor by user..." );
    }     // copy constructor by user

    void print(){
        puts( name );
    }
};

class B {
private:
    const char* name = "";

public:
    B( const char* temp ) : name( temp ){
        puts( "default constructor..." );
    }         // default constructor

    B( B&& other ) = default;

    void print(){
        puts( name );
    }
};

class C {
private:
    const char* name = "";

public:
    C( const char* temp ) : name( temp ){
        puts( "default constructor..." );
    }         // default constructor

    C( C&& other ) = delete;

    void print(){
        puts( name );
    }
};


int main(){

    A a_default( "a_default" );

    A a_move( std::move( a_default ) ); // or A a_move = std::move( a_default );

    A a2_move = static_cast< std::remove_reference< A >::type&& >( a_default );

    A ( *pf )( A ) = []( A obj ){ return obj; };

    A a3_move =  pf( A("") );

    puts( "-----------------------" );

    B b_default( "b_default" );
    B b_move( static_cast< std::remove_reference< B >::type&& >( b_default ) );

    puts( "-----------------------" );

    C c_default( "c_default" );
    C c_move = std::move( c_default );      // error
    // error: use of deleted function ‘C::C(C&&)’
}

/* output:

default constructor...
move constructor by user...
move constructor by user...
default constructor...
move constructor by user...



*/
