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

void print(){}  // with using this function, the below code does not work
                // it needs to call the function print recursively

template< typename First, typename... Tail >
void
print( First begin, Tail... rest ){
    std::cout << begin << ' ';
    print( rest... );

}

// overload resolution for int type
template< typename First >
void
print( First begin, const int arg ){
    begin( arg );
}

// overload resolution for float type
template< typename First >
void
print( First begin, const float arg ){
    begin( arg );
}

// overload resolution for character type
template< typename First >
void
print( First begin, const char arg ){
    begin( arg );
}




void one( int i ){ std::cout << "one: " << i << '\n'; }
void two( float f ){ std::cout << "two: " << f << '\n'; }
void three( char c ){ std::cout << "three: " << c << '\n'; }

int main(){

    print( "just variable: " , 1, 2.2, '3' );

    print( one, 1 );
    print( two, 2.2f );
    print( three, '3' );

}

/* output:


*/
