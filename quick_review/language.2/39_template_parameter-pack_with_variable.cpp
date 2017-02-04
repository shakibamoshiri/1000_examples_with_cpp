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

int main(){

    print( 1, 2, 3 );

}

/* output:


*/
