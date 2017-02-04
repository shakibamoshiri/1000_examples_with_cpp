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
// g( f( args... ) )             is expanded to f( f( e1, e2, e3 ) )

// **************************************************************

int f(){ return -2; }

template< typename First, typename... Tail >
int f( First begin, Tail... rest ){
    std::cout << "f was called... with args: ";
    std::cout << begin << '\n';
    f( rest... );
    return -1;
}

template< typename... PPE > // PPE is an acronym for Parameter Pack Expression
void print( PPE... args){

    f( f( args... ));    // okay
    //
    // first:       f( f( 1,2,3 ) )
    // then         f( -1 )

}

int main(){

    print( 1, 2, 3 );

}

/* output:

f was called... with args: 1
f was called... with args: 2
f was called... with args: 3
f was called... with args: -1

*/
