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
//  alias template


/******************/
#include <iostream>
#include <vector>
/******************/

template< typename T > using Vector = std::vector< T >;

int main(){

    Vector< int > v1 = { 1, 2, 3, 4 };
    for( int temp : v1 ) std::cout << temp << ' ';

}

/* output:


*/
