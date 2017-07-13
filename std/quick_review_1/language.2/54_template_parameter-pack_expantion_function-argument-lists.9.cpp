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
    std::cout << "f with three argument was called ";
    int sum = arg1 + arg2 + arg3;
    std::cout << sum << '\n';
    return sum;
}
int f( int arg1, int arg2 ){
    std::cout << "f with two argument was called ";
    int sum = arg1 + arg2;
    std::cout << sum << '\n';
    return sum;
}
int f( int arg1 ){
    std::cout << "f with one argument was called ";
    int sum = arg1;
    std::cout << sum << '\n';
    return sum;
}


template< typename... PPE > // PPE is an acronym for Parameter Pack Expression
void print( PPE... args){
    // error: too few argument, it is just like one argument
    // f( f(args...) );
    f( f( args... ), f( args... ), f( args... ) );    // okay
    //
    // first:       inner 'f' becomes 6
    // seconds:     middle 'f' becomes 6
    // then:        last 'f' become 6
    // and then outer 'f' become f( 6, 6, 6 )

}

int main(){


    print( 1, 2, 3 );

    puts( "" ); // just newline

    print( 1, 2 );

    puts( "" ); // just newline

    print( 1 );
}

/* output:

f with three argument was called 6
f with three argument was called 6
f with three argument was called 6
f with three argument was called 18

f with two argument was called 3
f with two argument was called 3
f with two argument was called 3
f with three argument was called 9

f with one argument was called 1
f with one argument was called 1
f with one argument was called 1
f with three argument was called 3
*/
