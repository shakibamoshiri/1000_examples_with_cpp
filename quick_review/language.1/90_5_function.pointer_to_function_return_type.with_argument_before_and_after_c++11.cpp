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
/// function

#include <iostream>

void f_one( const char* c_string ){
    std::cout << c_string << '\n';
}

// per-C++11 style
void ( *before_11() )( const char* ){
    return f_one;
}


// C++11 func returns a pointer to f_one
auto after_11() -> void( * )( const char* ){
    return f_one;
}

int main(){

    f_one( "this is f_one" );

    before_11()( "before C++ 11" );
    after_11()( "after C++ 11" );

}
/* output:

this is f_one
before C++ 11
after C++ 11

*/
