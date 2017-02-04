/*
            language 1
            **********
written and tested on code::block 16.01
                      Ubuntu 16.01
            **********
1. preprocessor
2. expression
3. declaration
4. initialization
5. function

*/
/// initialization

#include <iostream>
#include <utility>
#include <memory>

struct S {
    int integer;
    explicit S( int temp ) : integer( temp ) {}
};

int main(){

    // note:
    // Direct-initialization is more permissive than copy-initialization:
    // copy-initialization only considers non-explicit constructors and user-defined
    // conversation function, while direct-initialization considers all constructors
    // and implicit conversion sequences.

    std::string string ( "this is a string" );      // okay
    std::unique_ptr< int > uptr( new int( 2 ) );    // okay

    S s( 3 );   // okay

    S s2 = 3;   // error
}



/* output:


*/
