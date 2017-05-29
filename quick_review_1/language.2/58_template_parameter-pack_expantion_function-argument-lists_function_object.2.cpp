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
//  function argument lists


/******************/
#include <iostream>
/******************/

template< typename Return, typename... Argument>
struct S {};

template< typename Return, typename... Argument >
struct S< Return( Argument... ) > {

    // instance typedef int( *Type )( int );
    typedef Return( *Type )( Argument... );

    Type obj;

    S( Type temp ) : obj( temp ){}

    void operator()( Argument... args ){
        obj( args... );
    }
};

int one( int i ){
    std::cout << "one was called with value int  : " << i << '\n';
    return 0;
}

int two( int i, float f ){
    std::cout << "one was called with value int  : " << i << '\n';
    std::cout << "one was called with value float: " << f << '\n';
    return 0;
}

int three( int i, float f, char c ){
    std::cout << "one was called with int   : " << i << '\n';
    std::cout << "one was called with float : " << f << '\n';
    std::cout << "one was called with char  : " << c << '\n';
    return 0;
}


int main(){

    S< int( int ) > first = one;
    one( 1 );
    first( 11 );

    puts( "---------------" );

    S< int( int, float ) > second = two;
    two( 2, 2.2 );
    second( 22, 22.22 );

    puts( "---------------" );

    S< int ( int, float, char ) > third = three;
    three( 3, 3.3, '3' );
    third( 33, 33.33, '3' );

}

/* output:

one was called with value int  : 1
one was called with value int  : 11
---------------
one was called with value int  : 2
one was called with value float: 2.2
one was called with value int  : 22
one was called with value float: 22.22
---------------
one was called with int   : 3
one was called with float : 3.3
one was called with char  : 3
one was called with int   : 33
one was called with float : 33.33
one was called with char  : 3

*/
