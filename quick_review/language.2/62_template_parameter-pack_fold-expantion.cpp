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
//  fold expression


/******************/
#include <iostream>
/******************/

template< typename... PPE >
int sum( PPE... args ){
    std::cout <<  ( args + ... ) << '\n';;
    return ( args + ... );
}


int main(){
    std::cout << sum( 1, 2, 3 );
}

/* output:



*/
