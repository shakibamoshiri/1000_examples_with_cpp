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
//--------------------------------------------------------------
void print(){}  // match to the end

template< typename First, typename... Tail >
void
print( First begin, Tail... rest ){
    std::cout << begin << ' ';
    print( rest... );   // print( arg1, arg2, arg3, ... )
                        // print( arg1, arg2, ... )
                        // print( arg1, ... )
                        // print( ... ) == zero
                        // end of recursive call
}
//--------------------------------------------------------------
void print_2(){}    // match to the end

template< typename First, typename... Tail >
void
print_2( First begin, Tail... rest ){
    begin();
    print_2( rest... );     // like above
                            // f1() is called, then print_2( f2(), f3(), ... )
                            // f2() is called, then print_2( f3(), ... )
                            // f3() is called, then print_2( ... )
                            // end
                            // all three function was called.
}

void one(){ puts( "this is one" ); }
void two(){ puts( "this is two" ); }
void six(){ puts( "this is six" ); }
//--------------------------------------------------------------
template< typename Func, typename Arg >
void
print_3( Func function, Arg argument ){
    function( argument );       // very easy, f calls its argument
                                // so no recursive call is need
}

void a( int i ){   std::cout << i << '\n'; }
void b( float f ){ std::cout << f << '\n'; }
void c( char c ){  std::cout << c << '\n'; }
//--------------------------------------------------------------
template< typename Func, typename First, typename... Tail >
void
print_4( Func function, First begin, Tail... rest ){
    function( begin, rest... );     // this just expands to function( begin, arg1, arg2, arg3 )
                                    // so no recursive call is need
}

int aa( int a, int b ){ std::cout << a << ' ' << b << '\n'; }
int bbb( int a, float f, char c ){
    std::cout << a << ' ' << f << ' ' << c << '\n';
}
//--------------------------------------------------------------

/// result:
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
//

int main(){



}

/* output:


*/
