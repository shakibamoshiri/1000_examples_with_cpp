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

/// how parameter-pack is work?
// pack expression is a pattern by an ellipsis in which the name
// of the at least on parameter pack appears at least once
// is expanded into zero of more "comma-separated instantiation
// of the pattern where the name of the parameter pack is replaced
// by each of the types from the pack
//
// f( args... )             is expanded to f( e1, e2, e3 )
// f( ++args... )           is expanded to f( ++e1, ++e2, ++e3 )
// f( &args... )            is expanded to f( &e1, &e2, &e3 )
// f( n, args... )          is expanded to f( n, e1, e2, e3 )
// f( args..., n )          is expanded to f( e1, e2, e3, n )
// **************************************************************

int f( int arg1, int arg2, int arg3 ){
    std::cout << "I am called\n";
    int sum = arg1 + arg2 + arg3;
    std::cout << sum << ' ';
    return sum;
}

template< typename... PPE > // PPE is an acronym for Parameter Pack Expression
void print( PPE... args){
    f( f(args...) + args... );  // expands to => f( f( 1,2,3 ) + 1, f( 1,2,3 ) + 2, f( 1,2,3 ) + 3 )
                                //                   ....6.... + 1, ....6..... + 2, .....6.... + 3 = 24
}

int main(){

    int a,b,c;
    print( 1, 2, 3 );

}

/* output:

I am called
6 I am called
6 I am called
6 I am called
24

*/
