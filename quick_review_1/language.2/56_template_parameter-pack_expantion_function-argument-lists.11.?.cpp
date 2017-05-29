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
// g( f( args... ) )             is expanded to g( f( e1, e2, e3 ) )

// **************************************************************

// the force of compiler to use the argument in recursively call parameter-pack

void f(){}  // match to the end

template< typename First, typename... Tail >
void
f( First begin, Tail... rest ){
    f( rest... );
    std::cout << "begin: " << begin << ' ';  // I have to use this cout, otherwise it does not work, why? I do not know!
}

template<  typename... PPE > // PPE is an acronym for Parameter Pack Expression
void print(  PPE... args){

    f ( args... )  ;    // f( f (int) );

}

int one()                    { puts( "one was called" ); return 1;   }
int two( int, char )         { puts( "two was called" ); return 2;   }
int three( int, char, float ){ puts( "three was called" ); return 3; }

int main(){

    //print( one(), one(), one(), one(), two( 2, '2' ), three( 3, '3', 3.3 ), one(), one()  );
    f(1,2,2,3);

}

/* output:



*/
