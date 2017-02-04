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

template< typename Return, typename Argument = Return >
struct S {};

template< typename Return >
struct S< Return( Return ) > {

    // instance typedef int( *Type )( int );
    typedef Return( *Type )( Return );

    Type obj;

    S( Type temp ) : obj( temp ){}

    void operator()( Return value ){
        obj( value );
    }
};

int one( int temp ){
    std::cout << "one was called with value: " << temp << '\n';
    return temp;
}

int main(){

    S< int( int ) > first = one;
    one( 2 );
    first( 3 );

}

/* output:



*/
