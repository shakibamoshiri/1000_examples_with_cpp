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
/******************/

template< typename Return, typename Argument = Return >
struct S {};

template< typename Return >
struct S < Return ( * )() > {
    Return operator()( Return ( *pf )() ){
        pf();
    }
};

template< typename Return, typename Argument >
struct S < Return ( * )( Argument ) > {

    typedef Return ( *type )( Argument );       // okay no problem

    Return operator()( type pf, int value ){    // okay no problem
        pf( value );
    }

    Return operator()( Argument value  ){       // okay no problem
        return value;
    }

    Return operator()( Return*  ){              // here is my problem
        return ;
    }

};


void print( void  ){ std::cout << "print" << '\n'; }

void print( int value ){ std::cout << "value is " << value << '\n'; }

float print( float value ){ return value; }

int main(){

    // just void function | okay no problem
    S< void( * )() > p2f;
    p2f( print );

    // with typedef method | okay no problem
    S< void( * )( int ) >::type p2f_2 = print;
    p2f_2( 22 );

    // pass the value separately | also okay no problem
    S< void( * )( int ) > p2f_3;
    p2f_3( print, 33 );

    // pass the value and returns it | okay no problem
    S< float( * )( float ) > p2f_4;
    std::cout << p2f_4( print( 3.3f ) );

    // pass the void function with argument | here is my problem
    //
    S< void( * )( int ) > p2f_5;
    p2f_5( print( 2 ) );


}

/* output:


*/
