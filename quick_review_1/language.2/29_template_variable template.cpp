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
//  variable template

/******************/
#include <iostream>
/******************/

template< typename T > constexpr T pi = T( 3.141592 );


int main(){

    std::cout << pi< int > << '\n';

    std::cout << 10 * pi< int > << '\n';

    std::cout << pi< int > * pi< int > << '\n';

    puts( "-------------------" );

    std::cout << pi< float > << '\n';

    std::cout << 10 * pi< float > << '\n';

    std::cout << pi< float > * pi< float > << '\n';
}

/* output:
3
30
9
-------------------
3.14159
31.4159
9.8696


*/
