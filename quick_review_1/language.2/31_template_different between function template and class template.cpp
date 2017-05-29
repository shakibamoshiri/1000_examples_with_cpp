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
//  different between function template and class template


/******************/
#include <iostream>

/******************/

template< typename T > void print( T ){}

template< typename T > struct S { typedef T type; }

int main(){


    print( 1 ); // deduces form value ( object )

    S< int >::type i;   // deduces from type ( int, float, char, ... )

}

/* output:


*/
