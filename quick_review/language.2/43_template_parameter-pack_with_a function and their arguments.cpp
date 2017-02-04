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


template< typename Func, typename First, typename... Tail >
void
print( Func function, First begin, Tail... rest ){
    function( begin, rest... );

}


void one( int i ){
    std::cout << "int : " << i << '\n';
}
void two( float f, int i2 ){
    std::cout << "int : " << f  << '\n';
    std::cout << "char: " << i2 << '\n';
}
void three( const char* cstr, float f, int i ){
    std::cout << "cstr :" << cstr << '\n';
    std::cout << "float:" << f    << '\n';
    std::cout << "int  :" << i    << '\n';
}

int main(){



    print( one, 1 );
    print( two, 2.2, 2 );
    print( three, "three", 3.3, 3 );


}

/* output:

int : 1
int : 2.2
char: 2
cstr :three
float:3.3
int  :3

*/
